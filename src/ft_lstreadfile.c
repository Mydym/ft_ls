/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreadfile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 17:22:27 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/11 16:00:20 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>
#include <string.h>

/*
**Fonction pour recuperer le nom du fichier suivant, dans le repertoire pointe
**par dirp, et le stocker dans un nouvel element de la liste.
*/

t_file	*ft_lstreadfile(DIR *dirp, char *repo, t_opt *opt)
{
	t_file			*new;
	struct dirent	*file;
	char			*path;
	int				i;

	new = NULL;
	path = NULL;
	i = 0;
	errno = 0;
	while (repo && repo[i])
	{
		if (repo[i] == '/' && !repo[i + 1])
			path = ft_strdup(repo);
		i++;
	}
	if (!path)
		path = ft_strjoin(repo, "/");
	file = NULL;
	if ((file = readdir(dirp)))
		new = ft_lstfilenew(file->d_name, '-', path);
	if (errno != 0)
		ft_error(path, opt);
	free(path);
	return (new);
}
