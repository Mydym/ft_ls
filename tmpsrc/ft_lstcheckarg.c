/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcheckarg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 16:52:41 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/23 16:25:35 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**Fonction pour afficher les elements selon leur type.
**Affiche d'abord les fichiers dans l'ordre recu
**Puis le contenu de chaque dossier.
*/

void	ft_lstcheckarg(t_file **larg)
{
	while (*larg)
	{
		if ((*larg)->type == '-')
		{
			ft_verifaffich(*larg);
			*larg = (*larg)->next;
		}
		else if ((*larg) && (*larg)->next)
			*larg = (*larg)->next;
		else if (*larg)
			break ;
	}
	if (*larg)
	{
		while ((*larg)->prev)
			*larg = (*larg)->prev;
		while (*larg)
		{
			if ((*larg)->type == 'd')
				ft_verifaffich(*larg);
			*larg = (*larg)->next;
		}
	}
}
