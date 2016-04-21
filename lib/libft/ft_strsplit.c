/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 15:19:15 by vgrenier          #+#    #+#             */
/*   Updated: 2016/01/06 19:12:23 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_nbword(const char *str, char c)
{
	int		nb;
	int		len;

	nb = 0;
	len = 0;
	while (*str)
	{
		if (*str != c)
			len++;
		if ((*str == c || *(str + 1) == 0) && len != 0)
		{
			nb++;
			len = 0;
		}
		str++;
	}
	return (nb);
}

static char		**ft_filltab(const char *s, char c, int nb, char **tab)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (*s)
	{
		if (*s != c)
			len++;
		if ((*s == c || *(s + 1) == 0) && len != 0)
		{
			tab[i] = (char *)malloc((len + 1) * sizeof(char));
			if (tab[i] == NULL)
				return (NULL);
			if (*(s + 1) == 0 && *s != c)
				tab[i] = ft_strsub(s - len + 1, 0, len);
			else
				tab[i] = ft_strsub(s - len, 0, len);
			len = 0;
			i++;
		}
		s++;
	}
	tab[nb] = 0;
	return (tab);
}

char			**ft_strsplit(const char *s, char c)
{
	char		**tab;
	char		*str;
	int			nb;

	str = (char *)s;
	nb = ft_nbword(str, c);
	tab = (char **)malloc((nb + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	tab = ft_filltab(s, c, nb, tab);
	return (tab);
}
