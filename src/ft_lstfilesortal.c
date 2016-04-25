/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfilesortal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:26:31 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/25 17:22:15 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
