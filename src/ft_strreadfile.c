/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreadfile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 13:32:43 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/13 15:52:27 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <string.h>

char	*ft_strreadfile(DIR *dirp)
{
	char			*filename;
	struct dirent	*file;

	filename = NULL;
	if ((file = readdir(dirp)))
		filename = file->d_name;
	return (filename);
}
