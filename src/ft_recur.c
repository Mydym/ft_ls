/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 13:12:24 by vgrenier          #+#    #+#             */
/*   Updated: 2016/05/19 18:04:29 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*ft_recurarg(t_opt *option, char **larg, int k, int i)
{
	void	(*psort)(t_file **, t_file *, t_opt *);
	t_file	*elem;
	t_file	*new;

	elem = NULL;
	new = NULL;
	if (option->t)
		psort = &ft_lstargsorttime;
	else
		psort = &ft_lstargsortal;
	if (--k > 0)
		new = ft_recurarg(option, larg, k, i);
	if (larg[k])
	{
		if ((ft_lstisdir(larg[k])))
			elem = ft_lstfilenew(larg[k], 'd', "./");
		if ((ft_lstisfile(larg[k])))
			ft_putfilendl(elem = ft_lstfilenew(larg[k], '-', "./"), option);
	}
	if (elem)
		psort(&new, elem, option);
	new = ft_gotostart(new);
	if (k == i - 1)
		ft_recurfile(new, option, 0);
	return (new);
}

void		ft_recurfile(t_file *lstarg, t_opt *option, int x)
{
	static t_size	max;
	static int		k[1] = {0};

	if (!option->r || x == 0)
	{
		if (k[0] != 42)
		{
			k[0] = 42;
			max = ft_getmaxsize(lstarg);
		}
		if (lstarg->type == 'd' && x == 0)
		{
			k[0] = 0;
			ft_printdosname(lstarg);
			ft_recurdos(lstarg->name, option);
		}
		else if (!option->r)
			ft_putdetail(lstarg, option, max);
		if (option->r && lstarg->next)
			ft_recurfile(lstarg->next, option, 1);
		else if (lstarg->next)
			ft_recurfile(lstarg->next, option, x);
	}
	else if (option->r)
		ft_recurfilerev(lstarg, option, 0, max);
}

void		ft_recurfilerev(t_file *lstarg, t_opt *opt, int first, t_size max)
{
	t_file	*elem;

	if (opt->l)
		max = ft_getmaxsize(lstarg);
	lstarg = ft_gotofileend(lstarg);
	elem = lstarg;
	while (lstarg && lstarg->type == '-')
	{
		first = 1;
		ft_putdetail(lstarg, opt, max);
		if (lstarg->prev)
			lstarg = lstarg->prev;
		else
			break ;
	}
	lstarg = ft_gotoend(lstarg);
	if (lstarg->type == 'd' &&
			(ft_strcmp(elem->name, lstarg->name) != 0 || first == 0))
		ft_printrevdos(lstarg, first, opt);
}

void		ft_recurdos(char *doss, t_opt *option)
{
	void	(*psort)(t_file **, t_file *, t_opt *);
	DIR		*path;
	t_file	*lstfile;
	t_file	*elem;

	path = NULL;
	lstfile = NULL;
	if (option->t)
		psort = &ft_lstfilesorttime;
	else
		psort = &ft_lstfilesortal;
	if ((path = ft_opendir(doss)))
	{
		while ((elem = ft_lstreadfile(path, doss)))
		{
			lstfile = ft_gotostart(lstfile);
			ft_putfilendl(elem, option);
			psort(&lstfile, elem, option);
		}
		closedir(path);
	}
	lstfile = ft_gotostart(lstfile);
	if (lstfile)
		ft_recurfile(lstfile, option, 1);
	return ;
}
