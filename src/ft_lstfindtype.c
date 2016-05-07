/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfindtype.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 14:47:57 by vgrenier          #+#    #+#             */
/*   Updated: 2016/05/07 15:18:21 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**Fonction pour determiner le type de ficher d'un element.
*/

char		ft_testtype(struct stat filetype)
{
	char		type;

	type = '\0';
	if (S_ISREG(filetype.st_mode))
		type = '-';
	else if (S_ISDIR(filetype.st_mode))
		type = 'd';
	else if (S_ISCHR(filetype.st_mode))
		type = 'c';
	else if (S_ISBLK(filetype.st_mode))
		type = 'b';
	else if (S_ISFIFO(filetype.st_mode))
		type = 'p';
	else if (S_ISLNK(filetype.st_mode))
		type = 'l';
	else if (S_ISSOCK(filetype.st_mode))
		type = 's';
	return (type);
}

void		ft_lstfindtype(t_file *elem)
{
	char		type;
	struct stat	filetype;

	type = '\0';
	if (lstat(elem->name, &filetype) == 0)
	{
		type = ft_testtype(filetype);
		elem->type = type;
	}
	else if (lstat(elem->pathname, &filetype) == 0)
	{
		type = ft_testtype(filetype);
		elem->type = type;
	}
	return ;
}
