/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfilenew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 16:14:00 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/09 17:15:31 by vgrenier         ###   ########.fr       */
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

int			ft_cut_name(t_file *new, char *file, char *path)
{
	char		*tmp;

	while ((tmp = ft_strrchr(file, '/')) != NULL && file)
	{
		if (ft_strlen(tmp) > 1)
		{
			new->name = ft_strdup(tmp + 1);
			new->path = ft_strnew(ft_strlen(file) - ft_strlen(tmp + 1));
			new->path = ft_strncpy(new->path, file,
					ft_strlen(file) - ft_strlen(tmp + 1));
			break ;
		}
		else
			break ;
	}
	if ((!tmp || ft_strlen(tmp) <= 1) && file)
	{
		new->name = ft_strdup(file);
		new->path = ((path) ? ft_strdup(path) : ft_strdup(file));
		return (2);
	}
	if (new->name && new->path)
		return (1);
	return (0);
}

t_file		*ft_lstfilenew(char *filename, char type, char *path)
{
	t_file		*new;

	if (!(new = (t_file *)ft_memalloc(sizeof(t_file))))
		return (NULL);
	if (filename)
		ft_cut_name(new, filename, path);
	new->type = ((type) ? type : '-');
	ft_lstfileinit(new);
	if (ft_strcmp(new->name, new->path) != 0)
		new->pathname = ft_strjoin(new->path, new->name);
	else
		new->pathname = ft_strdup(new->name);
	return (new);
}
