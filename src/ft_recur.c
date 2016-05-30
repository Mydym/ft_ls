/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 13:12:24 by vgrenier          #+#    #+#             */
/*   Updated: 2016/05/30 17:46:18 by vgrenier         ###   ########.fr       */
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
	psort = ((option->t) ? &ft_lstargsorttime : &ft_lstargsortal);
	if (--k > 0)
		new = ft_recurarg(option, larg, k, i);
	if (larg[k])
	{
		if ((ft_lstisdir(larg[k], *option)))
			elem = ft_lstfilenew(larg[k], 'd', "./");
		else
			ft_putfilendl(elem = ft_lstfilenew(larg[k], '-', "./"), option);
	}
	if (elem)
		psort(&new, elem, option);
	new = ft_gotostart(new);
	if (k == i - 1 && new)
		ft_recurfile(new, option, i, i);
	return (new);
}

void		ft_recur_or_not(t_file *lstarg, t_opt *option, int x, int y)
{
	if (option->r)
		ft_recurfile(lstarg->next, option, x - 1, y);
	else
		ft_recurfile(lstarg->next, option, x - 1, y);
	return ;
}

/*void		ft_recur_or_not(t_file *lstarg, t_opt *option, int x)
{
	if (option->r)
		ft_recurfile(lstarg->next, option, x - 1, x);
	else
		ft_recurfile(lstarg->next, option, x - 1, x);
	return ;
}*/

void		ft_recurfile(t_file *lstarg, t_opt *option, int k, int i)
{
	static t_size	max;

	if (k == i)
		ft_maxinit(&max);
	if (!option->r)
	{
		if (k == i)
			max = ft_getmaxsize(lstarg, max);
		if (lstarg->type == '-')
			ft_putdetail(lstarg, option, max);
		else if (lstarg->type == 'd')
		{
//			if (k == i && option->gr)
//				ft_putendl("");
			ft_printdosname(lstarg, option);
			ft_recurdos(lstarg->name, option);
		}
		if (lstarg->next)
			ft_recur_or_not(lstarg, option, k, i);
	}
	else if (option->r)
		ft_recurfilerev(lstarg, option, 0, max);
}

/*void		ft_recurfile(t_file *lstarg, t_opt *option, int x, int i)
{
	static t_size	max;
	static int		k[1] = {0};
	(void)i;

	if ((x == 0 && k[0] != 42) || (x == 1 && k[0] != 42))
		ft_maxinit(&max);
	if (!option->r || x == 0)
	{
		if (k[0] != 42)
		{
			k[0] = 42;
			max = ft_getmaxsize(lstarg, max);
		}
		if (lstarg->type == 'd')
		{
			k[0] = 0;
			ft_printdosname(lstarg, option);
			ft_recurdos(lstarg->name, option);
		}
		else if (!option->r)
			ft_putdetail(lstarg, option, max);
		if (lstarg->next)
			ft_recur_or_not(lstarg, option, x);
	}
	else if (option->r)
		ft_recurfilerev(lstarg, option, 0, max);
}*/

void		ft_recurfilerev(t_file *lstarg, t_opt *opt, int first, t_size max)
{
	t_file	*elem;

	if (opt->l)
		max = ft_getmaxsize(lstarg, max);
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
	int		compt;

	path = NULL;
	lstfile = NULL;
	compt = 0;
	errno = 0;
	psort = ((option->t) ? &ft_lstargsorttime : &ft_lstargsortal);
	if ((path = ft_opendir(doss)))
	{
		while ((elem = ft_lstreadfile(path, doss)) != NULL)
		{
			compt++;
			lstfile = ft_gotostart(lstfile);
			ft_putfilendl(elem, option);
			psort(&lstfile, elem, option);
		}
		closedir(path);
	}
	if (errno != 0)
	{
		ft_putstr("ls: ");
		perror(doss);
	}
	lstfile = ft_gotostart(lstfile);
	ft_puttotal(lstfile, *option);
	if (lstfile)
		ft_recurfile(lstfile, option, compt, compt);
	lstfile = ft_gotostart(lstfile);
/*	if (option->gr && lstfile)
		ft_recurarg(option, ft_lst_to_char(lstfile, option), ft_lst_compt_elem(lstfile), ft_lst_compt_elem(lstfile));*/
	return ;
}
