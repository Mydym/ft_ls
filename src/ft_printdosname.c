/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdosname.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:53:20 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/10 11:59:23 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printdosname(t_file *elem, t_opt *option)
{
	t_file	*temp;

	temp = ft_gotostart(elem);
	if (ft_strcmp(elem->path, "./") == 0 && (!option->opt & F_RMAJ))
		ft_putstr(elem->name);
	else
		ft_putstr(elem->pathname);
	ft_putendl(":");
}
