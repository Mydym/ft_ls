/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 17:07:56 by vgrenier          #+#    #+#             */
/*   Updated: 2016/01/26 16:54:42 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_realloc(char *str, int len)
{
	char	*tmp;
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if ((tmp = (char *)malloc((len + 1) * sizeof(char))))
		if (ft_memcpy((void *)tmp, (void *)str, i + 1))
		{
			free(str);
			return ((void *)tmp);
		}
	return (NULL);
}
