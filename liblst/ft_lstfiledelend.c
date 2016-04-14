/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfiledelend.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 16:11:10 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/14 16:29:18 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

t_file		*ft_lstfiledelend(t_file **plst)
{
	t_file		*tmp;
	t_file		*one;

	one = *plst;
	while ((*plst)->next)
		*plst = (*plst)->next;
	tmp = (*plst)->prev;
	tmp->next = NULL;
	free(*plst);
	*plst = NULL;
	return (one);
}
