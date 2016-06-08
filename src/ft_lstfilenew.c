/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfilenew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 16:14:00 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/08 18:13:49 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**Fonction pour creer un nouvel element de type t_file
*/

t_file		*ft_lstfileinit(t_file *new)
{
	new->username = NULL;
	new->groupname = NULL;
	new->permus = NULL;
	new->permgp = NULL;
	new->permoth = NULL;
	new->perm = NULL;
	new->maj = -1;
	new->min = -1;
	new->size = 0;
	new->nblink = 0;
	new->sblock = 0;
	new->mtimenano = 0;
	new->mtime = 0;
	new->formattime = NULL;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_file		*ft_lstfilenew(char *filename, char type, char *path)
{
	t_file		*new;
	char		*tmp;
	char		*temp;

	if ((new = (t_file *)malloc(sizeof(t_file))) == NULL)
		return (NULL);
	if (filename)
	{
		temp = ft_strdup(filename);
		while ((tmp = ft_strrchr(temp, '/')) != NULL)
		{
			if (ft_strlen(tmp) > 1)
			{
				new->name = ft_strdup(tmp + 1);
				new->path = ft_strnew(ft_strlen(filename) - ft_strlen(tmp + 1));
				new->path = ft_strncpy(new->path, filename,
						ft_strlen(filename) - ft_strlen(tmp + 1));
				break ;
			}
			else
				break ;
			free(temp);
			temp = ft_strdup(tmp);
		}
		if (!tmp || ft_strlen(tmp) <= 1)
		{
			new->name = ft_strdup(filename);
			if (path)
				new->path = ft_strdup(path);
		}
	}
	if (type)
		new->type = type;
	else
		new->type = '-';
	ft_lstfileinit(new);
//	if (path)
//		new->path = ft_strdup(path);
//	new->path = path;
	new->pathname = ft_strjoin(new->path, new->name);
	return (new);
}
