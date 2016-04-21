/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreaddir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 13:32:34 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/13 15:17:24 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

char	**ft_strreaddir(const char *file)
{
	DIR		*doc;
	char	**list;
	int		i;

	i = 0;
	if ((list = (char **)malloc(512 * sizeof(char *))) != NULL)
		if ((doc = ft_opendir(file)) != NULL)
		{
			while ((list[i] = ft_strreadfile(doc)) != NULL)
				i++;
			closedir(doc);
		}
	return (list);
}
