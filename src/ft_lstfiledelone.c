/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfiledelone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 16:45:32 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/11 17:07:46 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Fonction pour supprimer l'element courant de la liste.
*/

static void	ft_lst_file_clear(t_file *elem)
{
	if (elem)
	{
		free(elem->path);
		free(elem->name);
		if (elem->pathname)
			free(elem->pathname);
		if (elem->perm)
		{
			free(elem->permus);
			free(elem->permgp);
			free(elem->permoth);
			free(elem->perm);
		}
		if (elem->formattime)
			free(elem->formattime);
	}
}

t_file		*ft_lstfiledelone(t_file **plst)
{
	if (*plst)
	{
		ft_lst_file_clear(*plst);
		free(*plst);
		*plst = NULL;
	}
	return (NULL);
}
