/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcheckarg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 16:52:41 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/22 17:17:24 by vgrenier         ###   ########.fr       */
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
			ft_putendl((*larg)->name);
			*larg = ft_lstfiledelone(larg);
		}
		else if ((*larg) && (*larg)->next)
			*larg = (*larg)->next;
		else if (*larg)
			break ;
	}
	while ((*larg)->prev)
		*larg = (*larg)->prev;
	while (*larg)
	{
		if ((*larg)->type == 'd')
		{
			ft_putchar('\n');
			ft_putstr((*larg)->name);
			ft_putstr(":\n");
			ft_lstaffichdos((*larg)->name);
		}
		*larg = (*larg)->next;
	}
}
