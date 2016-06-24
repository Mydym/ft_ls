/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstisdir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 13:45:34 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/05 15:02:21 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**Fonction qui renvoie un booleen : 1 si l'element est un dossier et 0 sinon.
*/

int		ft_find_typelink(char *name)
{
	struct stat	type;
	char		*tmp;

	if ((lstat(name, &type)) == 0)
	{
		if (S_ISDIR(type.st_mode))
			return (1);
	}
	else if ((tmp = ft_strjoin("/", name)) && (lstat(tmp, &type)) == 0)
	{
		errno = 0;
		if (S_ISDIR(type.st_mode))
			return (1);
		free(tmp);
	}
	return (0);
}

int		ft_charisdir(char *name, t_opt option)
{
	struct stat	type;
	char		*buff;

	buff = NULL;
	if ((lstat(name, &type)) == 0)
	{
		if (S_ISDIR(type.st_mode))
			return (1);
		else if (S_ISLNK(type.st_mode) && (!(option.opt & F_LMIN)))
		{
			buff = ft_strnew(1000);
			if (buff && readlink(name, buff, 1000) != -1)
			{
				if (ft_find_typelink(buff))
				{
					free(buff);
					return (1);
				}
			}
		}
	}
	if (buff)
		free(buff);
	return (0);
}

int		ft_lstisdir(t_file *elem, t_opt option)
{
	struct stat	type;
	char		*buff;

	buff = NULL;
	if ((lstat(elem->pathname, &type)) == 0 && !(option.opt & F_RMAJ &&
		option.opt & F_AMIN && (!ft_strcmp(elem->name, ".") ||
		!ft_strcmp(elem->name, ".."))))
	{
		if (S_ISDIR(type.st_mode))
			return (1);
		else if (S_ISLNK(type.st_mode) && (!(option.opt & F_LMIN)))
			if ((buff = ft_strnew(1000)))
				if (readlink(elem->pathname, buff, 1000) != -1)
					if (ft_charisdir(buff, option))
					{
						free(buff);
						return (1);
					}
	}
	if (buff)
		free(buff);
	return (0);
}
