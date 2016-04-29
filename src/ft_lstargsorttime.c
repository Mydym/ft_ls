/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstargsorttime.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 13:48:45 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/29 13:49:19 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**Fonction qui recupere l'heure de derniere modif d'un element en int et en
**format 'jour/mois/num/heure/annee'
*/

int		ft_gettime(t_file *plst)
{
	struct stat	m_time;

	while (plst)
	{
		if (plst)
		{
			plst->mtime = 0;
			plst->formattime = NULL;
		}
		if (stat(plst->name, &m_time) == 0)
		{
			plst->mtime = m_time.st_mtime;
			plst->formattime = ctime(&m_time.st_mtime);
		}
		plst = plst->next;
	}
	if (plst == NULL)
		return (1);
	return (0);
}

/*
**Fonction pour trier les arguments selon leur type (fichiers/.../dossiers)
**puis selon l'heure de derniere modification de chaque argument.
*/

void	ft_lstargsorttime(t_file **larg, t_file *elem)
{
	while ((*larg) && (*larg)->prev)
		*larg = (*larg)->prev;
	if (elem->type == '-')
		ft_lstfilesorttime(larg, elem);
	else if (ft_gettime(elem))
	{
		if (*larg)
		{
			while ((*larg)->type != 'd' && (*larg)->next)
				*larg = (*larg)->next;
			while (elem->mtime < (*larg)->mtime && (*larg)->next)
				*larg = (*larg)->next;
		}
		if (((*larg) && !(*larg)->next)
				&& (elem->mtime < (*larg)->mtime || (*larg)->type != 'd'))
			ft_lstfileaddend(larg, elem);
		else
			ft_lstfileadd(larg, elem);
	}
	return ;
}

/*
**Fonction pour tirer des fichiers selon l'heure de derniere modification
*/

void	ft_lstfilesorttime(t_file **plst, t_file *elem)
{
	if (ft_lstishidden(elem->name))
		return ;
	if (*plst && ft_gettime(elem))
		while ((elem->mtime - (*plst)->mtime < 0) && (*plst)->next
				&& (*plst)->type != 'd')
			*plst = (*plst)->next;
	if ((*plst) && !((*plst)->next) && (*plst)->type != 'd'
			&& (elem->mtime - (*plst)->mtime < 0))
		ft_lstfileaddend(plst, elem);
	else
		ft_lstfileadd(plst, elem);
	return ;
}
