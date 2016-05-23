/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdosname.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:53:20 by vgrenier          #+#    #+#             */
/*   Updated: 2016/05/23 14:43:40 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printdosname(t_file *elem)
{
	if (elem->prev)
		ft_putstr("\n");
	if (elem->prev || elem->next)
	{
		if (ft_strcmp(elem->path, "./") == 0)
			ft_putstr(elem->name);
		else
			ft_putstr(elem->pathname);
		ft_putendl(":");
	}
	return ;
}
