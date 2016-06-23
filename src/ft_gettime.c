/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 13:19:24 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/11 13:32:42 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Fonction qui recupere l'heure de derniere modif d'un element en int et en
** format 'jour/mois/num/heure/annee'
*/

static void	ft_formtimehour(t_file *plst, struct stat m_time)
{
	char	*alltime;
	char	*shorttime;

	alltime = ctime(&m_time.st_mtime);
	shorttime = ft_strsub(alltime, 4, ft_strlen(alltime) - 4);
	alltime = ft_strsub(shorttime, 0, ft_strlen(shorttime) - 9);
	free(shorttime);
	plst->formattime = alltime;
}

static void	ft_formtimeyear(t_file *plst, struct stat m_time)
{
	char	*alltime;
	char	*shorttime;
	char	*year;

	alltime = ctime(&m_time.st_mtime);
	shorttime = ft_strsub(alltime, 4, ft_strlen(alltime) - 18);
	year = ft_strsub(alltime, ft_strlen(alltime) - 6, 5);
	alltime = ft_strjoin(shorttime, year);
	free(shorttime);
	free(year);
	plst->formattime = alltime;
}

static void	ft_all_time(t_file *plst, struct stat m_time)
{
	char	*alltime;

	alltime = ctime(&m_time.st_mtime);
	plst->formattime = ft_strsub(alltime, 4, ft_strlen(alltime) - 5);
}

static void	ft_stocktime(t_file *plst, struct stat m_time, t_opt *option)
{
	time_t	local;

	local = 0;
	time(&local);
	if (option->opt & F_LMIN)
	{
		if (option->opt & F_TMAJ)
			ft_all_time(plst, m_time);
		else
		{
			if (plst->mtime > local - 15778800 && plst->mtime < local + 1)
				ft_formtimehour(plst, m_time);
			else
				ft_formtimeyear(plst, m_time);
		}
	}
}

int			ft_gettime(t_file *plst, t_opt *option)
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
			errno = 0;
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
