/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfindtype.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 14:47:57 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/29 17:37:01 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**Fonction pour determiner le type de ficher d'un element.
*/

t_file		*ft_lstfindtype(char *name)
{
	t_file		*elem;
	char		type;
	struct stat	filetype;

	type = '-';
	elem = NULL;
	if (stat(name, &filetype) != -1)
	{
		if (S_ISREG(filetype.st_mode))
			type = '-';
		if (S_ISDIR(filetype.st_mode))
			type = 'd';
		if (S_ISCHR(filetype.st_mode))
			type = 'c';
		if (S_ISBLK(filetype.st_mode))
			type = 'b';
		if (S_ISFIFO(filetype.st_mode))
			type = 'p';
		if (S_ISLNK(filetype.st_mode))
			type = 'l';
		if (S_ISSOCK(filetype.st_mode))
			type = 's';
		elem = ft_lstfilenew(name, type, "./");
	}
	return (elem);
}
