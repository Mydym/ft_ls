/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfilendl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 14:12:12 by vgrenier          #+#    #+#             */
/*   Updated: 2016/05/23 15:10:14 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_puttotal(t_file *elem, t_opt option)
{
	int		total;
	int		compt;

	total = 0;
	compt = 0;
	if (option.l == 1)
	{
		while (elem)
		{
			total += elem->sblock;
			compt++;
			elem = elem->next;
		}
		if (compt != 0)
		{
			ft_putstr("total ");
			ft_putnbr(total);
			ft_putchar('\n');
		}
	}
	return ;
}

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
	while (a < b)
	{
		ft_putchar(' ');
		a++;
	}
}

void	ft_putdetail(t_file *file, t_opt *option, t_size max)
{
	if (option->l)
	{
		ft_lstfindtype(file);
		ft_putchar(file->type);
		ft_putstr(file->perm);
		ft_putspace(ft_intlen(file->nblink), max.link, 0);
		ft_putnbr(file->nblink);
		ft_putstr(" ");
		ft_putstr(file->username);
		ft_putspace(ft_strlen(file->username), max.user + 2, 1);
		ft_putstr(file->groupname);
		ft_putspace(ft_strlen(file->groupname), max.group + 2, 1);
		ft_putspace(ft_intlen(file->size), max.taille, 1);
		ft_putnbr(file->size);
		ft_putstr(" ");
		ft_putstr(file->formattime);
		ft_putstr(" ");
		ft_putendl(file->name);
		ft_lstfiledelone(&file);
	}
	else
	{
		ft_putendl(file->name);
		ft_lstfiledelone(&file);
	}
}

void	ft_putfilendl(t_file *file, t_opt *option)
{
	if (option->l)
	{
		ft_gettime(file, option);
		ft_getfiledetail(file);
	}
}
