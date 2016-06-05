/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdosname.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:53:20 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/05 15:01:19 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printdosname(t_file *elem, t_opt *option, int pass)
{
	t_file	*temp;

	temp = ft_gotostart(elem);
	if (elem->prev || elem->next || ((option->opt & F_RMAJ) && pass != 1))
	{
		if (ft_strcmp(elem->path, "./") == 0 && (!option->opt & F_RMAJ))
			ft_putstr(elem->name);
		else
			ft_putstr(elem->pathname);
		ft_putendl(":");
	}
}
