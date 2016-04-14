/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreaddir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 17:10:51 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/14 17:34:04 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

t_file	**ft_lstreaddir(const char *file)
{
	t_file	**plst;
	t_file	*tmp;
	DIR		*doc;

	if ((plst = (t_file **)malloc(512 * sizeof(t_file *))) != NULL)
		if ((doc = ft_opendir(file)) != NULL)
		{
			while ((tmp = ft_lstreadfile(doc)) != NULL)
				ft_lstfileadd(plst, tmp);
			closedir(doc);
		}
	return (plst);
}
