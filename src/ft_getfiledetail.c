/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfiledetail.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 17:56:11 by vgrenier          #+#    #+#             */
/*   Updated: 2016/05/19 18:08:45 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_addlink(t_file *elem)
{
	char	*buff;

	buff = ft_strnew(512);
	if (readlink(elem->name, buff, 510) != -1)
	{
		ft_strcat(elem->name, " -> ");
		ft_strcat(elem->name, buff);
	}
	free(buff);
}

void	ft_stockfiledetail(t_file *file, struct stat detail)
{
	struct passwd	*id;
	struct group	*grp;

	if ((id = getpwuid(detail.st_uid)))
		if (id->pw_name)
			file->username = ft_strdup(id->pw_name);
	if ((grp = getgrgid(detail.st_gid)))
		if (grp->gr_name)
			file->groupname = ft_strdup(grp->gr_name);
	file->nblink = detail.st_nlink;
	file->size = detail.st_size;
	ft_permuser(detail, file);
	ft_permgroup(detail, file);
	ft_permother(detail, file);
	ft_permglobal(file);
	if (S_ISLNK(detail.st_mode))
		ft_addlink(file);
	return ;
}

void	ft_getfiledetail(t_file *file)
{
	struct stat		detail;

	if (ft_strcmp(file->path, "./") == 0 && lstat(file->name, &detail) == 0)
		ft_stockfiledetail(file, detail);
	else if (lstat(file->pathname, &detail) == 0)
		ft_stockfiledetail(file, detail);
}
