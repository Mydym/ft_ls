/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straffichdos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 11:55:40 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/13 11:59:52 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_straffichdos(char *path)
{
	char	**list;
	int		i;

	i = 0;
	if (path)
	{
		list = ft_strreaddir(path);
		while (list[i] != NULL)
		{
			ft_putendl(list[i]);
			i++;
		}
	}
	return ;
}
