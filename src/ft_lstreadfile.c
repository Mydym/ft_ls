/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreadfile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 17:22:27 by vgrenier          #+#    #+#             */
/*   Updated: 2016/05/30 17:46:20 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>
#include <string.h>

/*
**Fonction pour recuperer le nom du fichier suivant, dans le repertoire pointe
**par dirp, et le stocker dans un nouvel element de la liste.
*/

t_file	*ft_lstreadfile(DIR *dirp, char *repo)
{
	t_file			*new;
	struct dirent	*file;
	char			*path;

	new = NULL;
	path = ft_strdup(repo);
	path = ft_strcat(path, "/");
	file = NULL;
	errno = 0;
	if ((file = readdir(dirp)))
	{
//		if (file->d_type == DT_DIR)
//			new = ft_lstfilenew(file->d_name, 'd', path);
//		else
		new = ft_lstfilenew(file->d_name, '-', path);
	}
	else if (errno != 0)
		perror(path);
	free(path);
	return (new);
}
