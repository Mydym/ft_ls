/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:28:20 by vgrenier          #+#    #+#             */
/*   Updated: 2015/12/06 20:34:47 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		length;
	int		i;
	char	*string;

	i = 0;
	length = ft_strlen(s) + 1;
	string = (char *)malloc(length * sizeof(*string));
	if (string == NULL)
		return (string);
	while (s[i])
	{
		string[i] = (char)s[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}
