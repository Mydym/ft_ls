/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreaddir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 17:10:51 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/25 17:15:50 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**Fonction pour ouvrir un dossier et recuperer son contenu trie par ordre alpha
*/

t_file	*ft_lstreaddir(const char *file)
{
	t_file		*plst;
	t_file		*elem;
	DIR			*doc;

	plst = NULL;
	if ((doc = ft_opendir(file)) != NULL)
	{
		while ((elem = ft_lstreadfile(doc)) != NULL)
		{
			ft_lstfilesortal(&plst, elem);
			while (plst && plst->prev)
				plst = plst->prev;
		}
		closedir(doc);
	}
	return (plst);
}
