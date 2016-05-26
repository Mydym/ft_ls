/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreaddir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 17:10:51 by vgrenier          #+#    #+#             */
/*   Updated: 2016/05/09 11:38:54 by vgrenier         ###   ########.fr       */
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
	t_opt		*option;

	plst = NULL;
	option = NULL;
	ft_init(option);
	if ((doc = ft_opendir(file)) != NULL)
	{
		while ((elem = ft_lstreadfile(doc, (char *)file)) != NULL)
		{
			ft_lstfilesortal(&plst, elem, option);
			while (plst && plst->prev)
				plst = plst->prev;
		}
		closedir(doc);
	}
	return (plst);
}
