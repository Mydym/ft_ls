/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 14:50:02 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/11 17:01:57 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_permglobal(t_file *file)
{
	if (!file->perm)
		file->perm = ft_strnew(10);
	file->perm[9] = '\0';
	if (file->permus)
		file->perm = ft_strcat(file->perm, file->permus);
	if (file->permgp)
		file->perm = ft_strcat(file->perm, file->permgp);
	if (file->permoth)
		file->perm = ft_strcat(file->perm, file->permoth);
}

void	ft_permuser(struct stat detail, t_file *file)
{
	if (!file->permus)
		file->permus = ft_strnew(3);
	if (detail.st_mode & S_IRUSR)
		ft_strcat(file->permus, "r");
	else
		ft_strcat(file->permus, "-");
	if (detail.st_mode & S_IWUSR)
		ft_strcat(file->permus, "w");
	else
		ft_strcat(file->permus, "-");
	if (detail.st_mode & S_IXUSR)
		if (detail.st_mode & S_ISUID)
			ft_strcat(file->permus, "s");
		else
			ft_strcat(file->permus, "x");
	else if (detail.st_mode & S_ISUID)
		ft_strcat(file->permus, "S");
	else
		ft_strcat(file->permus, "-");
}

void	ft_permgroup(struct stat detail, t_file *file)
{
	if (!file->permgp)
		file->permgp = ft_strnew(3);
	if (detail.st_mode & S_IRGRP)
		ft_strcat(file->permgp, "r");
	else
		ft_strcat(file->permgp, "-");
	if (detail.st_mode & S_IWGRP)
		ft_strcat(file->permgp, "w");
	else
		ft_strcat(file->permgp, "-");
	if (detail.st_mode & S_IXGRP)
		if (detail.st_mode & S_ISGID)
			ft_strcat(file->permgp, "s");
		else
			ft_strcat(file->permgp, "x");
	else if (detail.st_mode & S_ISGID)
		ft_strcat(file->permgp, "S");
	else
		ft_strcat(file->permgp, "-");
}

void	ft_permother(struct stat detail, t_file *file)
{
	if (!file->permoth)
		file->permoth = ft_strnew(3);
	if (detail.st_mode & S_IROTH)
		ft_strcat(file->permoth, "r");
	else
		ft_strcat(file->permoth, "-");
	if (detail.st_mode & S_IWOTH)
		ft_strcat(file->permoth, "w");
	else
		ft_strcat(file->permoth, "-");
	if (detail.st_mode & S_IXOTH)
		if (detail.st_mode & S_ISVTX)
			ft_strcat(file->permoth, "t");
		else
			ft_strcat(file->permoth, "x");
	else if (detail.st_mode & S_ISVTX)
		ft_strcat(file->permoth, "T");
	else
		ft_strcat(file->permoth, "-");
}
