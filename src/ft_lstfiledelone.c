/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfiledelone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 16:45:32 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/22 17:22:43 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**Fonciton pour supprimer l'element courant de la liste.
*/

t_file		*ft_lstfiledelone(t_file **plst)
{
	t_file	*next;
	t_file	*prev;

	next = NULL;
	prev = NULL;
	if (*plst)
	{
		if ((*plst)->next)
			next = (*plst)->next;
		if ((*plst)->prev)
			prev = (*plst)->prev;
		free(*plst);
		*plst = NULL;
	}
	if (next && prev)
	{
		next->prev = prev;
		prev->next = next;
	}
	if (prev)
		return (prev);
	if (next)
		return (next);
	return (NULL);
}
