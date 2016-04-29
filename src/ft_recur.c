/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 13:12:24 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/29 18:30:33 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*ft_recurarg(t_opt *option, char **larg, int k, int i)
{
	void	(*psort)(t_file **, t_file *);
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
			elem = ft_lstfilenew(larg[k], '-', "./");
	}
	if (elem)
		psort(&new, elem);
	new = ft_gotostart(new);
	if (k == i - 1)
		ft_recurfile(new, option);
	return (new);
}

void		ft_recurfile(t_file *lstarg, t_opt *option)
{
	if (lstarg->type == '-')
		ft_putendl(lstarg->name);
	else if (lstarg->type == 'd')
	{
		if (lstarg->prev)
			ft_printdosname(lstarg->name, "\n");
		else if (lstarg->next)
			ft_printdosname(lstarg->name, "");
		ft_recurdos(lstarg->name, option);
	}
	if (lstarg->next)
		ft_recurfile(lstarg->next, option);
	return ;
}

void		ft_recurdos(char *doss, t_opt *option)
{
	void	(*psort)(t_file **, t_file *);
	DIR		*path;
	t_file	*lstfile;
	t_file	*elem;
//	char	*dossier;

	path = NULL;
	lstfile = NULL;
//	dossier = NULL;
	if (option->t)
		psort = &ft_lstfilesorttime;
	else
		psort = &ft_lstfilesortal;
	if ((path = ft_opendir(doss)))
	{
		while ((elem = ft_lstreadfile(path, doss)))
		{
//			if (elem->type == 'd')
//				dossier = elem->name;
			lstfile = ft_gotostart(lstfile);
			psort(&lstfile, elem);
		}
		closedir(path);
	}
	lstfile = ft_gotostart(lstfile);
	if (lstfile)
		ft_recurfile(lstfile, option);
//	if (option->gr && dossier)
//		ft_recurdos(dossier, option);
	return ;
}
