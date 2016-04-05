/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:55:14 by vgrenier          #+#    #+#             */
/*   Updated: 2015/12/06 20:41:56 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	carac;
	int		i;
	int		length;

	i = 0;
	carac = c;
	length = (int)ft_strlen(s);
	while (length - i >= 0)
	{
		if (s[length - i] == carac)
			return ((char *)&s[length - i]);
		i++;
	}
	return (NULL);
}
