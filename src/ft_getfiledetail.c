/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfiledetail.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 17:56:11 by vgrenier          #+#    #+#             */
/*   Updated: 2016/05/26 14:30:41 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_addlink(t_file *elem)
{
	char	*buff;
	char	*temp;

	if ((buff = ft_strnew(1000)) != NULL)
	{
		if (readlink(elem->name, buff, 1000) != -1)
		{
			temp = ft_strjoin(elem->name, " -> ");
			free(elem->name);
			elem->name = ft_strjoin(temp, buff);
			free(temp);
		}
		else if (readlink(elem->pathname, buff, 1000) != -1)
		{
			temp = ft_strjoin(elem->name, " -> ");
			free(elem->name);
			elem->name = ft_strjoin(temp, buff);
			free(temp);
		}
		free(buff);
	}
}

void	ft_stockfiledetail(t_file *file, struct stat detail)
{
	struct passwd	*id;
	struct group	*grp;

	if ((id = getpwuid(detail.st_uid)) && id->pw_name)
		file->username = ft_strdup(id->pw_name);
	if ((grp = getgrgid(detail.st_gid)) && grp->gr_name)
	{
		file->groupname = ft_strdup(grp->gr_name);
		file->groupid = grp->gr_gid;
	}
	file->nblink = detail.st_nlink;
	if (S_ISCHR(detail.st_mode) || S_ISBLK(detail.st_mode))
	{
		file->maj = major(detail.st_rdev);
		file->min = minor(detail.st_rdev);
	}
	file->size = (long)detail.st_size;
	file->sblock = detail.st_blocks;
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
