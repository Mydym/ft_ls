/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islink.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 15:42:03 by vgrenier          #+#    #+#             */
/*   Updated: 2016/05/23 17:03:09 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_islink(char *name)
{
	struct stat		file;

	if (lstat(name, &file) == 0)
		if (S_ISLNK(file.st_mode))
			return (1);
	return (0);
}
