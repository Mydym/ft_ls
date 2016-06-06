/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 14:05:02 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/06 16:15:22 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_ls(int argc, char **arg)
{
	t_opt		option;
	t_file		*plst;
	char		*path;
	int			opt;

	path = ft_strnew(1);
	path = ".";
	plst = NULL;
	opt = 0;
	if (argc > 1)
		opt = ft_option(arg, &option);
	else
		option.opt = 0;
	if (option.opt != 0 && opt != -1)
	{
		if (++opt > 1 && argc > opt)
			plst = ft_recurarg(&option, &arg[opt], argc - opt, argc - opt);
		else
			plst = ft_recurarg(&option, &path, argc - opt + 1, argc - opt + 1);
	}
	else if (argc > 1 && option.opt == 0 && opt != -1)
		plst = ft_recurarg(&option, &arg[1], argc - 1, argc - 1);
	else if (opt != -1)
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
