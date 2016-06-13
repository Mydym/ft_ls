/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstishidden.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 16:38:04 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/09 15:56:57 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_lstishidden(char *name)
{
	/* ft_putendl(name); */
	if (name && ft_strcmp(name, ".") != 0 && ft_strcmp(name, "..") != 0 &&
			(name[0] == '.' && ((name[1] == '\0') ||
				(name[1] == '.' && name[2] == '\0') ||
					ft_isascii(name[1]))))
	{
		/* ft_putendl("1"); */
		return (1);
	}
	/* ft_putendl("0"); */
	return (0);
}
