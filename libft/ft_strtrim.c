/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 14:41:11 by vgrenier          #+#    #+#             */
/*   Updated: 2015/12/06 20:46:06 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(const char *s)
{
	char	*str;
	int		len;
	int		i;
	int		j;
	int		k;

	len = ft_strlen(s);
	i = 0;
	j = 1;
	k = -1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while (s[len - j] == ' ' || s[len - j] == '\t' || s[len - j] == '\n')
		j++;
	len = len - j - i + 1;
	if (len <= 0)
		len = 0;
	str = (char *)malloc((len + 1) * sizeof(*str));
	if (str == NULL)
		return (NULL);
	while (++k < len)
		str[k] = s[i + k];
	str[k] = '\0';
	return (str);
}
