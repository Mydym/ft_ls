/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfiledelone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 16:45:32 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/10 13:31:07 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Fonction pour supprimer l'element courant de la liste.
*/

void		ft_lst_file_clear(t_file *elem)
{
	if (elem)
	{
		free(elem->path);
		free(elem->name);
		free(elem->pathname);
		free(elem->permus);
		free(elem->permgp);
		free(elem->permoth);
		free(elem->perm);
		free(elem->username);
		free(elem->groupname);
		free(elem->formattime);
	}
}

t_file		*ft_lstfiledelone(t_file **plst)
{
	t_file	*next;
	t_file	*prev;

	if (*plst)
	{
		ft_lst_file_clear(*plst);
		next = ((*plst)->next ? (*plst)->next : NULL);
		prev = ((*plst)->prev ? (*plst)->prev : NULL);
		free(*plst);
		*plst = NULL;
		if (next && prev)
		{
			next->prev = prev;
			prev->next = next;
		}
		if (prev && !next)
			prev->next = NULL;
		if (next && !prev)
			next->prev = NULL;
		if (prev)
			return (prev);
		if (next)
			return (next);
	}
	return (NULL);
}
