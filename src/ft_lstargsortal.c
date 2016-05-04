/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstargsortal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 13:56:42 by vgrenier          #+#    #+#             */
/*   Updated: 2016/05/04 13:50:35 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**Fonction pour trier les arguments (fichiers/.../dossiers) dans cet ordre
**Puis dans l'ordre alphabetique
*/

void	ft_lstargsortal(t_file **larg, t_file *elem)
{
	while ((*larg) && (*larg)->prev)
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
		if (((*larg) && !(*larg)->next) &&
				(ft_strcmp(elem->name, (*larg)->name) > 0))
			ft_lstfileaddend(larg, elem);
		else
			ft_lstfileadd(larg, elem);
	}
	return ;
}

/*
**Fonction pour ranger les elements dans la liste selon l'ordre alpha
*/

void	ft_lstfilesortal(t_file **plst, t_file *elem)
{
	int		i;

	i = -1;
	if (ft_lstishidden(elem->name))
		return ;
	if (*plst)
	{
		while ((i = ft_strcmp(elem->name, (*plst)->name) > 0) && (*plst)->next
				&& (*plst)->type != 'd')
			*plst = (*plst)->next;
	}
	if ((*plst) && !((*plst)->next) && (*plst)->type != 'd')
		if ((i = ft_strcmp(elem->name, (*plst)->name)) > 0)
			ft_lstfileaddend(plst, elem);
	if (i <= 0 || (*plst)->type == 'd')
		ft_lstfileadd(plst, elem);
	return ;
}
