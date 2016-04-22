/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfileaddend.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 17:48:41 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/22 17:20:42 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**Fonciton pour ajouter un element a la fin de la liste
*/

void	ft_lstfileaddend(t_file **plst, t_file *new)
{
	if (*plst)
	{
		while ((*plst)->next)
			*plst = (*plst)->next;
		(*plst)->next = new;
		new->prev = (*plst);
	}
	return ;
}
