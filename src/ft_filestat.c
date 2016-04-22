/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filestat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 15:31:40 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/22 17:36:37 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <time.h>

void	ft_filestat(t_file *elem)
{
	struct stat		file;

	if (stat(elem->name, &file) == 0)
	{
		elem->type = file.st_dev;
		elem->nblink = file.st_nlink;
		elem->size = file.st_size;
		elem->mtime = file.st_mtime;
//		elem->formattime = ctime(&elem->mtime);
	}
	return ;
}
