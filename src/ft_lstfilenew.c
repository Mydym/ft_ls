/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfilenew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 16:14:00 by vgrenier          #+#    #+#             */
/*   Updated: 2016/05/25 15:50:11 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**Fonction pour creer un nouvel element de type t_file
*/

t_file		*ft_lstfilenew(char *filename, char type, char *path)
{
	t_file		*new;

	if ((new = (t_file *)malloc(sizeof(t_file))) == NULL)
		return (NULL);
	if (filename != NULL)
		new->name = ft_strdup(filename);
	if (type)
		new->type = type;
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
	if (path)
		new->path = ft_strnew(ft_strlen(path));
	new->path = path;
	new->pathname = ft_strjoin(new->path, new->name);
	new->mtimenano = 0;
	new->mtime = 0;
	new->formattime = NULL;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
