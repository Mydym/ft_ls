/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:27:34 by vgrenier          #+#    #+#             */
/*   Updated: 2015/12/06 20:50:23 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	char		carac;

	i = 0;
	carac = c;
	while (i < (ft_strlen(s) + 1))
	{
		if (carac == s[i])
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
