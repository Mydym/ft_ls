/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfilendl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 14:12:12 by vgrenier          #+#    #+#             */
/*   Updated: 2016/05/05 16:20:37 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_stockfiledetail(t_file *file, struct stat detail)
{
	struct passwd	*id;
	struct group	*grp;

	if ((id = getpwuid(detail.st_uid)))
		file->username = id->pw_name;
	if ((grp = getgrgid(detail.st_gid)))
		file->groupname = grp->gr_name;
	file->nblink = detail.st_nlink;
	file->size = detail.st_size;
	ft_permuser(detail, file);
	ft_permgroup(detail, file);
	ft_permother(detail, file);
	ft_permglobal(file);
}

void	ft_getfiledetail(t_file *file)
{
	struct stat		detail;
	char			*pathname;

	pathname = ft_strstr(file->path, file->name);
	if ((lstat(file->name, &detail) == 0))
		ft_stockfiledetail(file, detail);
	else if (pathname && ft_strcmp(pathname, file->name) == 0 &&
			lstat(file->path, &detail) == 0)
		ft_stockfiledetail(file, detail);
	else if (lstat(ft_strcat(file->path, file->name), &detail) == 0)
		ft_stockfiledetail(file, detail);
}

void	ft_putfilendl(t_file *file, t_opt *option)
{
	if (!option->l)
		ft_putendl(file->name);
	else
	{
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
		ft_putstr(file->formattime);
		ft_putstr(" : ");
		ft_putendl(file->name);
	}
}
