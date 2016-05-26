/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaffichdos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 13:32:15 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/25 17:12:18 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**Fonction pour recuper le contenu d'un dossier avec lstreaddir
**Puis l'afficher fichier par fichier.
*/

void	ft_lstaffichdos(char *path)
{
	t_file	*plst;

	if (path)
	{
		plst = ft_lstreaddir(path);
		while (plst && plst->prev)
			plst = plst->prev;
		while (plst)
		{
			ft_putendl(plst->name);
			plst = plst->next;
		}
	}
	return ;
}
