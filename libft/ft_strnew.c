/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:52:44 by vgrenier          #+#    #+#             */
/*   Updated: 2016/01/06 13:48:19 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	str = (char *)malloc((size + 1) * sizeof(*str));
	if (str == NULL)
		return (NULL);
	i = 0;
	if (str)
	{
		while (i <= size)
		{
			str[i] = 0;
			i++;
		}
	}
	return (str);
}
