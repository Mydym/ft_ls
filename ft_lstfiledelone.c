/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfiledelone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 16:45:32 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/13 16:57:40 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

void	ft_lstfiledelone(t_file **plst)
{
	if (*plst)
	{
		if ((*plst)->name)
			free((*plst)->name);
		if ((*plst)->username)
			free((*plst)->username);
		if ((*plst)->groupname)
			free((*plst)->groupname);
		free(*plst);
		*plst = NULL;
	}
}
