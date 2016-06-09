/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstargsortal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 13:56:42 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/09 19:07:56 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**Fonction pour trier les arguments (fichiers/.../dossiers) dans cet ordre
**Puis dans l'ordre alphabetique
*/

void	ft_lstargsortal(t_file **larg, t_file *elem, t_opt *option)
{
	while ((*larg) && (*larg)->prev)
		*larg = (*larg)->prev;
	if (elem->type == '-')
		ft_lstfilesortal(larg, elem, option);
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
				(ft_strcmp(elem->name, (*larg)->name) > 0 ||
				((*larg)->type != 'd')))
			ft_lstfileaddend(larg, elem);
		else
			ft_lstfileadd(larg, elem);
	}
	return ;
}

/*
**Fonction pour ranger les elements dans la liste selon l'ordre alpha
*/

void	ft_lstfilesortal(t_file **plst, t_file *elem, t_opt *option)
{
	int		i;

	i = -1;
	if (!(option->opt & F_AMIN))
		if (ft_lstishidden(elem->name))
			return ;
	while ((*plst) && (*plst)->prev)
		*plst = (*plst)->prev;
	if (*plst)
	{
		while ((i = ft_strcmp(elem->name, (*plst)->name) > 0) && (*plst)->next
				&& (*plst)->type != 'd')
			*plst = (*plst)->next;
	}
	if ((*plst) && !((*plst)->next) && (*plst)->type != 'd' &&
		(i = ft_strcmp(elem->name, (*plst)->name)) > 0)
		ft_lstfileaddend(plst, elem);
	else if (i <= 0 || (*plst)->type == 'd')
		ft_lstfileadd(plst, elem);
	return ;
}
