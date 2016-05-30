/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfilendl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 14:12:12 by vgrenier          #+#    #+#             */
/*   Updated: 2016/05/30 17:46:19 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_putspace(int a, int b, int c)
{
	int		i;

	i = b - a;
	if (i < 0)
		i = 1;
	if (c == 0)
	{
		a = 0;
		b = i + 2;
	}
	else if (a == 0)
		a++;
	while (a <= b)
	{
		ft_putchar(' ');
		a++;
	}
}

void	ft_put_majandmin(t_file *file)
{
	if (file->type == 'c' || file->type == 'b')
	{
		ft_putspace(ft_intlen(file->maj), 3, 1);
		ft_putnbr(file->maj);
		ft_putstr(",");
		ft_putspace(ft_intlen(file->min), 3, 1);
		ft_putnbr(file->min);
	}
	else
	{
		ft_putspace(ft_intlen(file->size), 8, 1);
		ft_putnbr(file->size);
	}
}

void	ft_putotherdetail(t_file *file, t_size max)
{
	if (file->groupname != NULL)
	{
		ft_putstr(file->groupname);
		ft_putspace(ft_strlen(file->groupname), max.group, 1);
	}
	else
	{
		ft_putspace(ft_intlen(file->groupid), max.group, 1);
		ft_putnbr(file->groupid);
	}
	if (ft_strstr(file->pathname, "/dev/") != NULL)
		ft_put_majandmin(file);
	else
	{
		ft_putspace(ft_intlen(file->size), max.taille, 1);
		ft_putnbr(file->size);
	}
}

void	ft_putdetail(t_file *file, t_opt *option, t_size max)
{
	if (option->l)
	{
		ft_lstfindtype(file);
		ft_putchar(file->type);
		ft_putstr(file->perm);
		ft_putspace(ft_intlen(file->nblink), max.link + 1, 1);
		ft_putnbr(file->nblink);
		ft_putstr(" ");
		ft_putstr(file->username);
		ft_putspace(ft_strlen(file->username), max.user + 1, 1);
		ft_putotherdetail(file, max);
		ft_putstr(" ");
		ft_putstr(file->formattime);
		ft_putstr(" ");
	}
	ft_putendl(file->name);
	if (!option->r && !option->gr)
		ft_lstfiledelone(&file);
}

void	ft_putfilendl(t_file *file, t_opt *option)
{
	if (option->l)
	{
		ft_gettime(file, option);
		ft_getfiledetail(file);
	}
}
