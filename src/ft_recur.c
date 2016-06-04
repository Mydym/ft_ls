/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 13:12:24 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/04 16:34:21 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*ft_recurarg(t_opt *option, char **larg, int k, int i)
{
	static int	pass[1] = {0};
	void		(*psort)(t_file **, t_file *, t_opt *);
	t_file		*elem;
	t_file		*new;

	elem = NULL;
	new = NULL;
	psort = ((option->t) ? &ft_lstargsorttime : &ft_lstargsortal);
	if (--k > 0)
		new = ft_recurarg(option, larg, k, i);
	if (larg[k])
	{
		if ((ft_charisdir(larg[k], *option)))
			elem = ft_lstfilenew(larg[k], 'd', "");
		else if ((ft_lstisfile(larg[k])))
			ft_putfilendl(elem = ft_lstfilenew(larg[k], '-', ""), option);
	}
	if (elem)
		psort(&new, elem, option);
	new = ft_gotostart(new);
	if (k == i - 1 && new)
	{
		if (i == 2)
			pass[0]++;
		else
			pass[0] += 2;
		ft_recurfile(new, option, i, i, pass[0]);
	}
	return (new);
}

void		ft_recur_or_not(t_file *lstarg, t_opt *option, int x, int y, int pass)
{
	if (x > 1)
	{
		if (option->r)
			ft_recurfile(lstarg->next, option, x - 1, y, pass);
		else
			ft_recurfile(lstarg->next, option, x - 1, y, pass);
	}
	return ;
}

void		ft_recurfile(t_file *lstarg, t_opt *option, int k, int i, int pass)
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
			if (pass != 1)
				ft_putchar('\n');
			ft_printdosname(lstarg, option, pass);
			ft_recurdos(lstarg->name, option, pass);
		}
		if (lstarg->next)
			ft_recur_or_not(lstarg, option, k, i, pass);
	}
	else if (option->r)
		ft_recurfilerev(lstarg, option, max, i, pass);
}

void		ft_recurfilerev(t_file *lstarg, t_opt *opt, t_size max, int i, int pass)
{
	if (opt->l)
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
		if (pass != 1)
			ft_putchar('\n');
		ft_printdosname(lstarg, opt, pass);
		ft_recurdos(lstarg->name, opt, pass);
		if (lstarg->prev && lstarg->prev->type == 'd')
			lstarg = lstarg->prev;
		else
			break ;
	}
//	lstarg = ft_gotostart(lstarg);
//	ft_lstfiledel(&lstarg);
}

void		ft_recurdos(char *doss, t_opt *option, int pass)
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
		while ((elem = ft_lstreadfile(path, doss)))
		{
			lstfile = ft_gotostart(lstfile);
			ft_putfilendl(elem, option);
			psort(&lstfile, elem, option);
			if ((ft_lstishidden(elem->name) == 0 && !option->a) || option->a)
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
	ft_puttotal(lstfile, *option);
	if (lstfile)
		ft_recurfile(lstfile, option, compt, compt, pass);
	lstfile = ft_gotostart(lstfile);
	if (option->gr && lstfile)
	{
//		if ((compt = ft_lst_compt_elem(lstfile)) > 0)
//			ft_putchar('\n');
		ft_recurarg(option, ft_lst_to_char(lstfile, option, &compt), compt, compt);
	}
	return ;
}
