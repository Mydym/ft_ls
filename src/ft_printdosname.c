/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdosname.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:53:20 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/29 13:07:05 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printdosname(char *name, char *space)
{
	ft_putstr(space);
	ft_putstr(name);
	ft_putendl(":");
	return ;
}