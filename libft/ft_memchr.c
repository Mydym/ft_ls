/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:12:47 by vgrenier          #+#    #+#             */
/*   Updated: 2015/12/06 20:27:07 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		carac;
	size_t				i;

	str = (const unsigned char *)s;
	carac = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == carac)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
