/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizemax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 12:44:31 by vgrenier          #+#    #+#             */
/*   Updated: 2016/05/12 19:01:21 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_maxinit(t_size *max)
{
	max->link = 0;
	max->user = 0;
	max->group = 0;
	max->taille = 0;
}

t_size	ft_getmaxsize(t_file *lst)
{
	t_size	max;
	int		user;
	int		group;

	ft_maxinit(&max);
	while (lst)
	{
		if (lst->username)
			user = (int)ft_strlen(lst->username);
		if (lst->groupname)
			group = (int)ft_strlen(lst->groupname);
		if (user > max.user)
			max.user = user;
		if (group > max.group)
			max.group = group;
		if (ft_intlen(lst->nblink) > max.link)
			max.link = ft_intlen(lst->nblink);
		if (ft_intlen(lst->size) > max.taille)
			max.taille = ft_intlen(lst->size);
		lst = lst->next;
	}
	return (max);
}
