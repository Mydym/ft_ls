/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfilendl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 14:12:12 by vgrenier          #+#    #+#             */
/*   Updated: 2016/05/04 18:48:30 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_getfiledetail(t_file *file)
{
	struct stat		detail;
	struct passwd	*id;
	struct group	*grp;
	char			*pathname;

	pathname = ft_strstr(file->path, file->name);
	if ((lstat(file->name, &detail) == 0))
	{
//		ft_putstr("test");
		if ((id = getpwuid(detail.st_uid)))
			file->username = id->pw_name;
		if ((grp = getgrgid(detail.st_gid)))
			file->groupname = grp->gr_name;
		file->nblink = detail.st_nlink;
		file->size = detail.st_size;
		if (detail.st_mode & S_IRWXU)
		{
			file->permus = ft_strnew(3);
			ft_strcat(file->permus, "rwx");
		}
		if (file->permus)
		{
			file->perm = ft_strnew(3);
			file->perm = ft_strjoin(file->perm, file->permus);
		}
	}
	else if (pathname && ft_strcmp(pathname, file->name) == 0 &&
			lstat(file->path, &detail) == 0)
	{
		if ((id = getpwuid(detail.st_uid)))
			file->username = id->pw_name;
		if ((grp = getgrgid(detail.st_gid)))
			file->groupname = grp->gr_name;
		file->nblink = detail.st_nlink;
		file->size = detail.st_size;
//		if (detail.st_mode == S_IRWXU)
//			ft_strcat(file->permus, "rwx");
//		else if (detail.st_mode != S_IRWXU)
//		{
//			if (detail.st_mode == S_IRUSR)
//				ft_strcat(file->permus, "r");
//			if (detail.st_mode == S_IWUSR)
//				ft_strcat(file->permus, "w");
//			if (detail.st_mode == S_IXUSR)
//				ft_strcat(file->permus, "x");
//		}
	}
	else if (lstat(ft_strcat(file->path, file->name), &detail) == 0)
	{
		if ((id = getpwuid(detail.st_uid)))
			file->username = id->pw_name;
		if ((grp = getgrgid(detail.st_gid)))
			file->groupname = grp->gr_name;
		file->nblink = detail.st_nlink;
		file->size = detail.st_size;
/*		if (detail.st_mode == S_IRWXU)
			ft_strcat(file->permus, "rwx");
		else if (detail.st_mode != S_IRWXU)
		{
			if (detail.st_mode == S_IRUSR)
				ft_strcat(file->permus, "r");
			if (detail.st_mode == S_IWUSR)
				ft_strcat(file->permus, "w");
			if (detail.st_mode == S_IXUSR)
				ft_strcat(file->permus, "x");
		}*/
	}
}

void	ft_putfilendl(t_file *file, t_opt *option)
{
	if (!option->l)
		ft_putendl(file->name);
	else
	{
//		ft_putstr("Je passe par la\n");
		ft_lstfindtype(file);
		ft_gettime(file);
		ft_getfiledetail(file);
		ft_putchar(file->type);
		if (file->perm)
			ft_putstr(file->perm);
		ft_putstr(" ");
		ft_putnbr(file->nblink);
		ft_putstr(" ");
		ft_putstr(file->username);
		ft_putstr(" ");
		ft_putstr(file->groupname);
		ft_putstr("  ");
		ft_putnbr(file->size);
		ft_putstr("  ");
		if (file->formattime)
			ft_putstr(file->formattime);
		ft_putstr(" : ");
		ft_putendl(file->name);
	}
}
