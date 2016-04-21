/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfilesortal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:26:31 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/21 12:35:44 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_lstfilesortal(t_file **plst, t_file *elem)
{
	int		i;

	i = -1;
	if (elem->name[0] != '.')
	{
		if (*plst)
		{
			while ((i = ft_strcmp(elem->name, (*plst)->name) > 0) && (*plst)->next)
				*plst = (*plst)->next;
		}
		if ((*plst) && !((*plst)->next))
			if ((i = ft_strcmp(elem->name, (*plst)->name)) > 0)
				ft_lstfileaddend(plst, elem);
		if (i <= 0)
			ft_lstfileadd(plst, elem);
	}
	return ;
}
