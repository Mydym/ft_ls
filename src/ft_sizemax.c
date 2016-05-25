/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizemax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 12:44:31 by vgrenier          #+#    #+#             */
/*   Updated: 2016/05/25 18:49:44 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_maxinit(t_size *max)
{
	max->link = 0;
	max->user = 0;
	max->group = 0;
	max->taille = 0;
	max->maj = 0;
	max->min = 0;
}

t_size	ft_getmaxsize(t_file *lst, t_size max)
{
	int		user;
	int		group;

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
		if (lst->maj != -1 || lst->min != -1)
		{
			if (ft_intlen(lst->maj) > max.maj)
				max.maj = ft_intlen(lst->maj);
			if (ft_intlen(lst->min) > max.min)
				max.min = ft_intlen(lst->min);
		}
		lst = lst->next;
	}
	return (max);
}
