/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfiledelone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 16:45:32 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/05 17:21:05 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Fonction pour supprimer l'element courant de la liste.
*/

t_file		*ft_lstfiledelone(t_file **plst)
{
	t_file	*next;
	t_file	*prev;

	if (*plst)
	{
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
