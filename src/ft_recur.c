/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 13:12:24 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/11 17:03:25 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*ft_recurarg(t_opt *opt, char **larg, int k, int i)
{
	void		(*psort)(t_file **, t_file *, t_opt *);
	t_file		*elem;
	t_file		*new;

	elem = NULL;
	new = NULL;
	psort = ((opt->opt & F_TMIN) ? &ft_lstargsorttime : &ft_lstargsortal);
	if ((i == 1 && k > 1) || (--k > 0))
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
	opt->tour = ((k == i - 1) ? opt->tour + 1 : opt->tour);
	((elem) ? psort(&new, elem, opt) : 0);
	new = ft_gotostart(new);
	((k == i - 1 && new) ? ft_recurfile(new, opt, i, i) : 0);
	return (new);
}

void		ft_recur_or_not(t_file *lstarg, t_opt *option, int x, int y)
{
	if (x > 1 && lstarg->next)
		ft_recurfile(lstarg->next, option, x - 1, y);
	return ;
}

void		ft_recurfile(t_file *lstarg, t_opt *opt, int k, int i)
{
	static t_size	max;

	if (k == i)
		ft_maxinit(&max);
	if (opt->opt & F_RMIN)
		ft_recurfilerev(lstarg, opt, max, i);
	else if (lstarg)
	{
		if (k == i)
			max = ft_getmaxsize(lstarg, max);
		if (lstarg->type == '-')
			ft_putdetail(lstarg, opt, max);
		else if (lstarg->type == 'd')
			ft_recurdir(lstarg, opt, k, i);
		if (k == 1 && !(OPTRMAJ))
			ft_lstfiledel(&lstarg);
		if (lstarg)
			ft_recur_or_not(lstarg, opt, k, i);
	}
}

void		ft_recurfilerev(t_file *lstarg, t_opt *opt, t_size max, int i)
{
	int		k;

	k = i;
	if (opt->opt & F_LMIN)
		max = ft_getmaxsize(lstarg, max);
	lstarg = ft_gotofileend(lstarg);
	while (lstarg && lstarg->type == '-' && i > 0)
	{
		ft_putdetail(lstarg, opt, max);
		i--;
		if (lstarg->prev)
			lstarg = lstarg->prev;
		else
			break ;
	}
	lstarg = ft_gotoend(lstarg);
	while (lstarg && lstarg->type == 'd' && i > 0)
	{
		ft_recurdir(lstarg, opt, i, k);
		i--;
		if (!(lstarg->prev && lstarg->prev->type == 'd'))
			break ;
		lstarg = lstarg->prev;
	}
	((lstarg && !(OPTRMAJ)) ? ft_lstfiledel(&lstarg) : 0);
}

void		ft_recurdir(t_file *lstdir, t_opt *opt, int k, int i)
{
	void	(*psort)(t_file **, t_file *, t_opt *);
	t_file	*lstfile;
	char	*path;
	int		x;

	psort = ((opt->opt & F_TMIN) ? &ft_lstargsorttime : &ft_lstargsortal);
	path = ((ft_charisdir(lstdir->pathname, *opt)) ? ft_strdup(lstdir->pathname)
			: ft_strdup(lstdir->name));
	if (i > 1 || (i >= 1 && opt->opt & F_RMAJ && opt->tour > 0))
	{
		if (k != i || (OPTRMAJ))
			ft_putchar('\n');
		ft_printdosname(lstdir, opt);
	}
	if ((lstfile = ft_readdir(path, opt, psort)) != NULL)
	{
		x = ft_compt_lst(lstfile);
		ft_puttotal(lstfile, *opt);
		ft_recurfile(lstfile, opt, x, x);
		if ((OPTRMAJ) && lstfile)
			ft_recurarg(opt, ft_lst_to_char(lstfile, opt, &x), x, x);
	}
	free(path);
	((!lstfile && errno != 0) ? ft_error(lstdir->name) : 0);
	((k == 1 && (OPTRMAJ)) ? ft_lstfiledel(&lstdir) : 0);
}
