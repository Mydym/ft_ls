/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pchar_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <vgrenier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 15:40:55 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/19 15:40:55 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_pchar_del(char **s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		ft_strdel(s + i);
		i++;
	}
	free(s);
}
