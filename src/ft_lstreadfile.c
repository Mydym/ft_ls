/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreadfile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 17:22:27 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/09 18:10:05 by vgrenier         ###   ########.fr       */
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
	path = NULL;
	if (repo)
	{
		if (ft_strcmp(repo, "/") != 0 && repo[ft_strlen(repo)] != '/')
			path = ft_strjoin(repo, "/");
		else
			path = ft_strdup(repo);
	}
	file = NULL;
	errno = 0;
	if ((file = readdir(dirp)))
		new = ft_lstfilenew(file->d_name, '-', path);
	free(path);
	return (new);
}
