/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfileaddend.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 17:48:41 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/21 17:25:02 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_lstfileaddend(t_file **plst, t_file *new)
{
	while ((*plst)->next)
		*plst = (*plst)->next;
	(*plst)->next = new;
	new->prev = (*plst);
	return ;
}
