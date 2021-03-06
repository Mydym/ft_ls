/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfileadd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 16:30:26 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/05 16:41:08 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**Fonction pour ajouter un element dans la liste a la place de l'element courant
*/

void		ft_lstfileadd(t_file **plst, t_file *new)
{
	if (plst)
	{
		if (*plst != NULL)
		{
			if ((*plst)->prev)
			{
				((*plst)->prev)->next = new;
				new->prev = (*plst)->prev;
			}
			else
				new->prev = NULL;
			(*plst)->prev = new;
			new->next = *plst;
			*plst = new;
		}
		else
			*plst = new;
	}
	return ;
}
