/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstargsorttime.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 13:48:45 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/03 14:45:26 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**Fonction pour trier les arguments selon leur type (fichiers/.../dossiers)
**puis selon l'heure de derniere modification de chaque argument.
*/

void	ft_lstargsorttime(t_file **larg, t_file *elem, t_opt *option)
{
	*larg = ft_gotostart(*larg);
	if (elem->type == '-')
		ft_lstfilesorttime(larg, elem, option);
	else if (ft_gettime(elem, option))
	{
		if (*larg)
		{
			while ((*larg)->type != 'd' && (*larg)->next)
				*larg = (*larg)->next;
			while (elem->mtime < (*larg)->mtime && (*larg)->next)
				*larg = (*larg)->next;
		}
		if ((*larg) && (elem->mtime < (*larg)->mtime || (*larg)->type != 'd'))
			ft_lstfileaddend(larg, elem);
		else if ((*larg && elem->mtime == (*larg)->mtime))
			ft_lstsorttimenano(larg, elem);
		else
			ft_lstfileadd(larg, elem);
	}
	return ;
}

/*
**Fonction pour tirer des fichiers selon l'heure de derniere modification
*/

void	ft_lstfilesorttime(t_file **plst, t_file *elem, t_opt *option)
{
	if (!option->a)
		if (ft_lstishidden(elem->name))
			return ;
	if (ft_gettime(elem, option))
	{
		while (*plst && (elem->mtime < (*plst)->mtime) &&
				(*plst)->next && (*plst)->type != 'd')
			*plst = (*plst)->next;
		if ((*plst) && (*plst)->type != 'd'
				&& (elem->mtime < (*plst)->mtime))
			ft_lstfileaddend(plst, elem);
		else if ((*plst && elem->mtime == (*plst)->mtime))
			ft_lstsorttimenano(plst, elem);
		else
			ft_lstfileadd(plst, elem);
	}
	return ;
}

void	ft_lstsorttimenano(t_file **larg, t_file *elem)
{
	while (elem->mtimenano == (*larg)->mtimenano && (*larg)->next)
	{
		if (ft_strcmp(elem->name, (*larg)->name) <= 0)
		{
			ft_lstfileadd(larg, elem);
			break ;
		}
		*larg = (*larg)->next;
	}
	if (!(*larg)->next && ft_strcmp(elem->name, (*larg)->name) > 0
				&& elem->mtimenano == (*larg)->mtimenano)
	{
		ft_lstfileaddend(larg, elem);
		return ;
	}
	else if (!(*larg)->next && elem->mtimenano == (*larg)->mtimenano)
	{
		ft_lstfileadd(larg, elem);
		return ;
	}
	while ((*larg)->next)
	{
		if (elem->mtimenano > (*larg)->mtimenano)
		{
			ft_lstfileadd(larg, elem);
			break ;
		}
		else
			*larg = (*larg)->next;
	}
	if (elem->mtimenano > (*larg)->mtimenano || !(*larg)->next)
		ft_lstfileaddend(larg, elem);
}
