/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstargsorttime.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 13:48:45 by vgrenier          #+#    #+#             */
/*   Updated: 2016/05/10 12:37:31 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**Fonction qui recupere l'heure de derniere modif d'un element en int et en
**format 'jour/mois/num/heure/annee'
*/

int		ft_gettime(t_file *plst, t_opt *option)
{
	struct stat	m_time;

	while (plst)
	{
		if (lstat(plst->name, &m_time) == 0)
			ft_stocktime(plst, m_time, option);
		else if (lstat(plst->pathname, &m_time) == 0)
			ft_stocktime(plst, m_time, option);
		if (plst->next)
			plst = plst->next;
		else
			break ;
	}
	if (plst->mtimenano != 0)
		return (1);
	return (0);
}

void	ft_stocktime(t_file *plst, struct stat m_time, t_opt *option)
{
	char	*time;
	char	*shorttime;
	char	*year;

	plst->mtime = m_time.st_mtimespec.tv_sec;
	plst->mtimenano = m_time.st_mtimespec.tv_nsec + SEC_TO_NSEC;
	if (option->l)
	{
		time = ft_strdup(ctime(&m_time.st_mtime));
		shorttime = ft_strsub(time, 4, ft_strlen(time) - 4);
		free(time);
		year = ft_strsub(shorttime, ft_strlen(shorttime) - 5, 4);
		time = ft_strnew(ft_strlen(shorttime) - 8);
		time = ft_strncpy(time, shorttime, ft_strlen(shorttime) - 9);
		ft_strcat(time, " ");
		free(shorttime);
		shorttime = ft_strjoin(time, year);
		free(time);
		free(year);
		plst->formattime = shorttime;
	}
}

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
		ft_lstfileaddend(larg, elem);
	else if (!(*larg)->next && elem->mtimenano == (*larg)->mtimenano)
		ft_lstfileadd(larg, elem);
	while (elem->mtimenano < (*larg)->mtimenano && (*larg)->next)
		*larg = (*larg)->next;
	if (elem->mtimenano < (*larg)->mtimenano)
		ft_lstfileaddend(larg, elem);
	else if (elem->mtimenano > (*larg)->mtimenano)
		ft_lstfileadd(larg, elem);
}
