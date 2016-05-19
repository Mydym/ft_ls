/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstargsorttime.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 13:48:45 by vgrenier          #+#    #+#             */
/*   Updated: 2016/05/19 14:59:19 by vgrenier         ###   ########.fr       */
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
		if (ft_strcmp(plst->path, "./") == 0 && lstat(plst->name, &m_time) == 0)
		{
			plst->mtime = m_time.st_mtimespec.tv_sec;
			plst->mtimenano = m_time.st_mtimespec.tv_nsec + SEC_TO_NSEC;
			ft_stocktime(plst, m_time, option);
		}
		else if (lstat(plst->pathname, &m_time) == 0)
		{
			plst->mtime = m_time.st_mtimespec.tv_sec;
			plst->mtimenano = m_time.st_mtimespec.tv_nsec + SEC_TO_NSEC;
			ft_stocktime(plst, m_time, option);
		}
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
	char	*alltime;
	char	*shorttime;
	time_t	local;

	time(&local);
	if (option->l)
	{
		if (plst->mtime > local - 15778800 && plst->mtime < local + 3600)
		{
			alltime = ft_strdup(ctime(&m_time.st_mtime));
			shorttime = ft_strsub(alltime, 4, ft_strlen(alltime) - 4);
			free(alltime);
			alltime = ft_strnew(ft_strlen(shorttime) - 8);
			alltime = ft_strncpy(alltime, shorttime, ft_strlen(shorttime) - 9);
			free(shorttime);
			plst->formattime = alltime;
		}
		else
		{
			alltime = ft_strdup(ctime(&m_time.st_mtime));
			shorttime = ft_strsub(alltime, ft_strlen(alltime) - 5, 4);
			free(alltime);
			plst->formattime = shorttime;
		}
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
