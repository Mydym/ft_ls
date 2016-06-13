/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfiledel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 16:38:35 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/10 13:31:11 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**Fonction pour supprimer et free une liste entiere.
*/

void	ft_lstfiledel(t_file **plst)
{
	t_file	*tmp;

	*plst = ft_gotostart(*plst);
	while (plst && *plst)
	{
		if ((*plst)->next)
			tmp = (*plst)->next;
		else
			tmp = NULL;
		ft_lstfiledelone(plst);
		*plst = tmp;
	}
}
