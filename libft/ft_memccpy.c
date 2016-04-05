/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:04:27 by vgrenier          #+#    #+#             */
/*   Updated: 2015/12/06 20:26:38 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*s1;
	const unsigned char	*s2;
	unsigned char		carac;
	size_t				i;

	i = 0;
	s1 = (unsigned char *)dst;
	s2 = (const unsigned char *)src;
	carac = (unsigned char)c;
	while (i < n)
	{
		s1[i] = s2[i];
		if (s2[i] == carac)
			return (&s1[i + 1]);
		i++;
	}
	return (NULL);
}
