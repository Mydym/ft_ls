/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:38:40 by vgrenier          #+#    #+#             */
/*   Updated: 2016/01/06 19:04:20 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*s1;
	const unsigned char	*s2;
	int					i;

	s1 = dst;
	s2 = src;
	i = len;
	if (src > dst)
		ft_memcpy(dst, src, len);
	else
		while (--i >= 0)
			s1[i] = s2[i];
	return (dst);
}
