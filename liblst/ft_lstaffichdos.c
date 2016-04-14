/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaffichdos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 13:32:15 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/14 17:34:03 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_lstaffichdos(char *path)
{
	t_file	**plst;

	if (path)
	{
		plst = ft_lstreaddir(path);
		while (*plst)
		{
			ft_putendl((*plst)->name);
			*plst = (*plst)->next;
		}
	}
	return ;
}
