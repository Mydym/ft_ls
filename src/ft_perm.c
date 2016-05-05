/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 14:50:02 by vgrenier          #+#    #+#             */
/*   Updated: 2016/05/05 15:53:21 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_permglobal(t_file *file)
{
	if (file->permus)
	{
		if (!file->perm)
			file->perm = ft_strnew(9);
		file->perm = ft_strjoin(file->perm, file->permus);
	}
	if (file->permgp)
	{
		if (!file->perm)
			file->perm = ft_strnew(9);
		file->perm = ft_strjoin(file->perm, file->permgp);
	}
	if (file->permoth)
	{
		if (!file->perm)
			file->perm = ft_strnew(9);
		file->perm = ft_strjoin(file->perm, file->permoth);
	}
}

void	ft_permuser(struct stat detail, t_file *file)
{
	if (detail.st_mode & S_IRUSR)
	{
		if (!file->permus)
			file->permus = ft_strnew(3);
		ft_strcat(file->permus, "r");
	}
	else
		ft_strcat(file->permus, "-");
	if (detail.st_mode & S_IWUSR)
	{
		if (!file->permus)
			file->permus = ft_strnew(3);
		ft_strcat(file->permus, "w");
	}
	else
		ft_strcat(file->permus, "-");
	if (detail.st_mode & S_IXUSR)
	{
		if (!file->permus)
			file->permus = ft_strnew(3);
		ft_strcat(file->permus, "x");
	}
	else
		ft_strcat(file->permus, "-");
}

void	ft_permgroup(struct stat detail, t_file *file)
{
	if (detail.st_mode & S_IRGRP)
	{
		if (!file->permgp)
			file->permgp = ft_strnew(3);
		ft_strcat(file->permgp, "r");
	}
	else
		ft_strcat(file->permgp, "-");
	if (detail.st_mode & S_IWGRP)
	{
		if (!file->permgp)
			file->permgp = ft_strnew(3);
		ft_strcat(file->permgp, "w");
	}
	else
		ft_strcat(file->permgp, "-");
	if (detail.st_mode & S_IXGRP)
	{
		if (!file->permgp)
			file->permgp = ft_strnew(3);
		ft_strcat(file->permgp, "x");
	}
	else
		ft_strcat(file->permgp, "-");
}

void	ft_permother(struct stat detail, t_file *file)
{
	if (detail.st_mode & S_IROTH)
	{
		if (!file->permoth)
			file->permoth = ft_strnew(3);
		ft_strcat(file->permoth, "r");
	}
	else
		ft_strcat(file->permoth, "-");
	if (detail.st_mode & S_IWOTH)
	{
		if (!file->permoth)
			file->permoth = ft_strnew(3);
		ft_strcat(file->permoth, "w");
	}
	else
		ft_strcat(file->permoth, "-");
	if (detail.st_mode & S_IXOTH)
	{
		if (!file->permoth)
			file->permoth = ft_strnew(3);
		ft_strcat(file->permoth, "x");
	}
	else
		ft_strcat(file->permoth, "-");
}
