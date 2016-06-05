/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 13:12:24 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/05 19:22:29 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*ft_recurarg(t_opt *opt, char **larg, int k, int i)
{
	static int	pass[1] = {0};
	void		(*psort)(t_file **, t_file *, t_opt *);
	t_file		*elem;
	t_file		*new;

	elem = NULL;
	new = NULL;
	psort = ((opt->opt & F_TMIN) ? &ft_lstargsorttime : &ft_lstargsortal);
	if (--k > 0)
		new = ft_recurarg(opt, larg, k, i);
	if (larg[k])
	{
		if ((ft_charisdir(larg[k], *opt)))
			elem = ft_lstfilenew(larg[k], 'd', "");
		else if ((ft_lstisfile(larg[k])))
			ft_putfilendl(elem = ft_lstfilenew(larg[k], '-', ""), opt);
	}
	if (elem)
		psort(&new, elem, opt);
	new = ft_gotostart(new);
	if (k == i - 1 && new)
	{
		if (new->type == '-' && i != 1)
			pass[0]++;
		else if (i != 1)
			pass[0]++;
		ft_recurfile(new, opt, i, i, pass[0]);
	}
	return (new);
}

void		ft_recur_or_not(t_file *lstarg, t_opt *option, int x, int y, int pass)
{
	if (x > 0)
	{
		if (option->opt & F_RMIN)
			ft_recurfile(lstarg->next, option, x - 1, y, pass);
		else
			ft_recurfile(lstarg->next, option, x - 1, y, pass);
	}
	return ;
}

void		ft_recurfile(t_file *lstarg, t_opt *opt, int k, int i, int pass)
{
	static t_size	max;

	if (k == i)
		ft_maxinit(&max);
	if (opt->opt & F_RMIN)
		ft_recurfilerev(lstarg, opt, max, i, pass);
	else
	{
		if (k == i)
			max = ft_getmaxsize(lstarg, max);
		if (lstarg->type == '-')
			ft_putdetail(lstarg, opt, max);
		else if (lstarg->type == 'd')
		{
			if (++pass != 1)
				ft_putchar('\n');
			ft_printdosname(lstarg, opt, pass);
			ft_recurdos(lstarg->name, opt, pass);
		}
		if (lstarg && lstarg->next)
			ft_recur_or_not(lstarg, opt, k, i, pass);
	}
	if (k == 1 && (!(opt->opt & F_RMAJ)))
	{
		lstarg = ft_gotostart(lstarg);
		ft_lstfiledel(&lstarg);
	}
}

void		ft_recurfilerev(t_file *lstarg, t_opt *opt, t_size max, int i, int pass)
{
	if (opt->opt & F_LMIN)
		max = ft_getmaxsize(lstarg, max);
	lstarg = ft_gotofileend(lstarg);
	while (lstarg && lstarg->type == '-' && i-- > 0)
	{
		ft_putdetail(lstarg, opt, max);
		if (lstarg->prev)
			lstarg = lstarg->prev;
		else
			break ;
	}
	lstarg = ft_gotoend(lstarg);
	while (lstarg && lstarg->type == 'd' && i-- > 0)
	{
		if (++pass != 1)
			ft_putchar('\n');
		ft_printdosname(lstarg, opt, pass);
		ft_recurdos(lstarg->name, opt, pass);
		if (lstarg->prev && lstarg->prev->type == 'd')
			lstarg = lstarg->prev;
		else
			break ;
	}
	if (!(opt->opt & F_RMAJ))
	{
		lstarg = ft_gotostart(lstarg);
		ft_lstfiledel(&lstarg);
	}
}

void		ft_recurdos(char *doss, t_opt *opt, int pass)
{
	void	(*psort)(t_file **, t_file *, t_opt *);
	DIR		*path;
	t_file	*lstfile;
	t_file	*elem;
	int		compt;

	path = NULL;
	lstfile = NULL;
	compt = 0;
	errno = 0;
	psort = ((opt->opt & F_TMIN) ? &ft_lstargsorttime : &ft_lstargsortal);
	if ((path = ft_opendir(doss)))
	{
		while ((elem = ft_lstreadfile(path, doss)))
		{
			lstfile = ft_gotostart(lstfile);
			ft_putfilendl(elem, opt);
			psort(&lstfile, elem, opt);
			if ((ft_lstishidden(elem->name) == 0 && !(opt->opt & F_AMIN))
					|| opt->opt & F_AMIN)
				compt++;
		}
		closedir(path);
	}
/*	if (errno != 0)
	{
		ft_putstr("ls: ");
		perror(elem->name);
	}*/
	lstfile = ft_gotostart(lstfile);
	ft_puttotal(lstfile, *opt);
	if (lstfile)
		ft_recurfile(lstfile, opt, compt, compt, pass);
	lstfile = ft_gotostart(lstfile);
	if (opt->opt & F_RMAJ && lstfile)
	{
		ft_recurarg(opt, ft_lst_to_char(lstfile, opt, &compt), compt, compt);
		lstfile = ft_gotostart(lstfile);
		ft_lstfiledel(&lstfile);
	}
	return ;
}
