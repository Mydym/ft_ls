/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfiledel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 16:38:35 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/13 16:55:27 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_lstfiledel(t_file **plst)
{
	if ((*plst)->next)
		ft_lstfiledel(&((*plst)->next));
	if (*plst)
	{
		ft_lstfiledelone(plst);
	}
}
