/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 14:05:02 by vgrenier          #+#    #+#             */
/*   Updated: 2016/05/19 15:28:24 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_ls(int argc, char **arg)
{
	t_opt		option;
	t_file		*plst;
	char		*path;

	path = ft_strnew(1);
	path = ".";
	plst = NULL;
	if (argc > 1)
		option = ft_option(arg);
	else
		ft_init(&option);
	if (option.none == 0)
	{
		if (argc > 2)
			plst = ft_recurarg(&option, &arg[2], argc - 2, argc - 2);
		else
			plst = ft_recurarg(&option, &path, argc - 1, argc - 1);
	}
	else if (argc > 1 && option.none == 1)
		plst = ft_recurarg(&option, &arg[1], argc - 1, argc - 1);
	else
		plst = ft_recurarg(&option, &path, argc, argc);
}

t_file		*ft_gotostart(t_file *lst)
{
	while (lst && lst->prev)
		lst = lst->prev;
	return (lst);
}

t_file		*ft_gotoend(t_file *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

t_file		*ft_gotofileend(t_file *lst)
{
	while (lst && lst->type == '-')
	{
		if (lst->next && lst->next->type == '-')
			lst = lst->next;
		else
			break ;
	}
	return (lst);
}

void		ft_printrevdos(t_file *lst, int first, t_opt *option)
{
	while (lst && lst->type == 'd')
	{
		if (lst->next || first != 0)
		{
			ft_printdosname(lst);
			first = 0;
		}
		else if (lst->prev)
			ft_printdosname(lst);
		ft_recurdos(lst->name, option);
		if (lst->prev)
			lst = lst->prev;
		else
			break ;
	}
}
