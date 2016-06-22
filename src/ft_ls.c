/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 14:05:02 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/09 20:26:13 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_file	*ft_recur_argv(t_opt *opt, char **larg, int k, int i)
{
	t_file	*recu;

	recu = ft_recurarg(opt, larg, k, i);
	ft_recurfile(recu, opt, i, i);
	return (recu);
}

void			ft_ls(int argc, char **arg)
{
	t_opt	option;
	char	*path;
	int		len;

	path = NULL;
	if (argc > 1)
		arg = ft_split_ar_op(arg, &option);
	if (argc <= 1 || arg == NULL)
		path = ft_strdup(".");
	else
	{
		len = ft_ppchar_nb_str(arg);
		arg = ft_alsort_arg(arg);
	}
	if (argc > 1 && arg != NULL)
		ft_recur_argv(&option, arg, len, len);
	else
		ft_recur_argv(&option, &path, 1, 1);
	if (path)
		free(path);
	if (option.opt & F_ERR_EX)
		exit(1);
	return ;
}

t_file			*ft_gotostart(t_file *lst)
{
	while (lst && lst->prev)
		lst = lst->prev;
	return (lst);
}

t_file			*ft_gotoend(t_file *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

t_file			*ft_gotofileend(t_file *lst)
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
