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

t_file		*ft_recur_argv(t_opt *opt, char **larg, int k, int i)
{
	t_file	*recu;

	recu = ft_recurarg(opt, larg, k, i);
	ft_recurfile(recu, opt, i, i);
	return (recu);
}

void		ft_ls(int argc, char **arg)
{
	t_opt		option;
	t_file		*plst;
	char		*pat;
	int			opt;

	pat = ft_strdup(".");
	plst = NULL;
	opt = ((argc > 1) ? ft_option(arg, &option) : 0);
	option.opt = ((argc > 1) ? option.opt : 0);
	arg = ((argc >= opt + 1) ? ft_alsort_arg(arg) : arg);
	if (option.opt != 0 && opt != -1)
	{
		if (++opt > 1 && argc > opt)
			plst = ft_recur_argv(&option, &arg[opt], argc - opt, argc - opt);
		else
			plst = ft_recur_argv(&option, &pat, argc - opt + 1, argc - opt + 1);
	}
	else if (argc > 1 && option.opt == 0 && opt != -1)
		plst = ft_recur_argv(&option, &arg[opt], argc - opt, argc - opt);
	else if (opt != -1)
		plst = ft_recur_argv(&option, &pat, argc, argc);
	free(pat);
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
