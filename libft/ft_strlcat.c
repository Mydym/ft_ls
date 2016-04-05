/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:51:41 by vgrenier          #+#    #+#             */
/*   Updated: 2015/12/06 20:51:44 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	n;
	size_t	len;

	n = size;
	i = 0;
	j = -1;
	while (n-- != 0 && dst[i])
		i++;
	len = i;
	n = size - i;
	if (n == 0)
		return (size + ft_strlen(src));
	while (src[++j])
	{
		if (n != 1)
		{
			dst[i] = (char)src[j];
			i++;
			n--;
		}
	}
	dst[i] = '\0';
	return (len + j);
}
