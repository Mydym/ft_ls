/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstargsortal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 13:56:42 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/23 16:34:24 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**Fonction pour trier les arguments (fichiers/.../dossiers) dans cet ordre
**Puis dans l'ordre alphabetique
*/

void	ft_lstargsortal(t_file **larg, t_file *elem)
{
	if ((*larg))
		while ((*larg)->prev)
			*larg = (*larg)->prev;
	if (elem->type == '-')
		ft_lstfilesortal(larg, elem);
	else
	{
		if (*larg)
		{
			while ((*larg)->type != 'd' && (*larg)->next)
				*larg = (*larg)->next;
			while ((ft_strcmp(elem->name, (*larg)->name) > 0) && (*larg)->next)
				*larg = (*larg)->next;
		}
		if ((*larg) && !(*larg)->next)
			if ((ft_strcmp(elem->name, (*larg)->name) > 0))
				ft_lstfileaddend(larg, elem);
		if (!(*larg) || ft_strcmp(elem->name, (*larg)->name) <= 0)
			ft_lstfileadd(larg, elem);
	}
	return ;
}
