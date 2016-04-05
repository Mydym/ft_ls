/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:09:08 by vgrenier          #+#    #+#             */
/*   Updated: 2015/12/06 20:41:28 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] && i < n)
	{
		while (s1[i + j] == s2[j] && s2[j] && i + j < n)
			j++;
		if (s2[j] == '\0')
			return ((char *)&s1[i]);
		j = 0;
		i++;
	}
	if (s2[j] == '\0')
		return ((char *)&s1[i]);
	return (NULL);
}
