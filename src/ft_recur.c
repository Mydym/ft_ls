/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 13:12:24 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/09 20:26:12 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*ft_recurarg(t_opt *opt, char **larg, int k, int i)
{
	int			tab[2];
	static int	pass = 0;
	void		(*psort)(t_file **, t_file *, t_opt *);
	t_file		*elem;
	t_file		*new;

	elem = NULL;
	new = NULL;
	psort = ((opt->opt & F_TMIN) ? &ft_lstargsorttime : &ft_lstargsortal);
	if (--k > 0)
		new = ft_recurarg(opt, larg, k, i);
	if (k >= 0 && larg[k])
	{
		if ((ft_charisdir(larg[k], *opt)))
			elem = ft_lstfilenew(larg[k], 'd', "");
		else if ((ft_lstisfile(larg[k])))
			ft_putfilendl(elem = ft_lstfilenew(larg[k], '-', ""), opt);
		else
			ft_error(larg[k]);
	}
	((elem) ? psort(&new, elem, opt) : 0);
	new = ft_gotostart(new);
	tab[0] = i;
	tab[1] = pass;
	if (k == i - 1 && new && new->type == '-')
		tab[1] += 0;
	else
		tab[1] += 1;
//	tab[1] = ((k == i - 1 && new && new->type == '-') ? pass + 1 : pass);
	((k == i - 1 && new) ? ft_recurfile(new, opt, i, tab) : 0);
	return (new);
}

void		ft_recur_or_not(t_file *lstarg, t_opt *option, int x, int y[2])
{
	if (x > 0)
		ft_recurfile(lstarg->next, option, x - 1, y);
	return ;
}

void		ft_recurfile(t_file *lstarg, t_opt *opt, int k, int i[2])
{
	static t_size	max;

	if (k == i[0])
		ft_maxinit(&max);
	if (opt->opt & F_RMIN)
		ft_recurfilerev(lstarg, opt, max, i);
	else
	{
		if (k == i[0])
			max = ft_getmaxsize(lstarg, max);
		if (lstarg->type == '-')
			ft_putdetail(lstarg, opt, max);
		else if (lstarg->type == 'd')
		{
			ft_recurdir(lstarg, opt, i[1]);
			i[1] = ((i[1]) ? 0 : i[1]++);
		}
		if (lstarg && lstarg->next)
			ft_recur_or_not(lstarg, opt, k, i);
	}
}

void		ft_recurfilerev(t_file *lstarg, t_opt *opt, t_size max, int i[2])
{
	if (opt->opt & F_LMIN)
		max = ft_getmaxsize(lstarg, max);
	lstarg = ft_gotofileend(lstarg);
	while (lstarg && lstarg->type == '-' && i[0]-- > 0)
	{
		ft_putdetail(lstarg, opt, max);
		if (lstarg->prev)
			lstarg = lstarg->prev;
		else
			break ;
	}
	lstarg = ft_gotoend(lstarg);
	while (lstarg && lstarg->type == 'd' && i[0]-- > 0)
	{
		ft_recurdir(lstarg, opt, i[1]);
		i[1] = ((i[1]) ? 0 : i[1]++);
		if (lstarg->prev && lstarg->prev->type == 'd')
			lstarg = lstarg->prev;
		else
			return ;
	}
}

void		ft_recurdir(t_file *lstdir, t_opt *opt, int pass)
{
	void	(*psort)(t_file **, t_file *, t_opt *);
	t_file	*lstfile;
	char	*path;
	int		k[2];

	psort = ((opt->opt & F_TMIN) ? &ft_lstargsorttime : &ft_lstargsortal);
	path = ((ft_charisdir(lstdir->pathname, *opt)) ? ft_strdup(lstdir->pathname)
			: ft_strdup(lstdir->name));
	k[0] = 0;
	k[1] = pass;
	if (k[1] != 1)
		ft_putchar('\n');
	ft_printdosname(lstdir, opt, k[1]);
	if ((lstfile = ft_readdir(path, opt, psort)) != NULL)
	{
		k[0] = ft_compt_lst(lstfile);
		ft_puttotal(lstfile, *opt);
		ft_recurfile(lstfile, opt, k[0], k);
		if (opt->opt & F_RMAJ && lstfile)
			ft_recurarg(opt, ft_lst_to_char(lstfile, opt, k), k[0], k[0]);
	}
}
