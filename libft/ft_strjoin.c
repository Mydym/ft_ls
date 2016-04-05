/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 18:54:07 by vgrenier          #+#    #+#             */
/*   Updated: 2015/12/06 20:36:38 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		lens1;
	int		lens2;
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = 0;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	str = (char *)malloc((lens1 + lens2 + 1) * sizeof(*str));
	if (str == NULL)
		return (NULL);
	while (++i < lens1 + lens2)
	{
		if (i < lens1)
			str[i] = (char)s1[i];
		else
		{
			str[i] = (char)s2[j];
			j++;
		}
	}
	str[i] = '\0';
	return (str);
}
