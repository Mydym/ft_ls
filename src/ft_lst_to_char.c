/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 16:44:49 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/10 17:15:01 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_lst_compt_dir(t_file *lst, t_opt *opt)
{
	int		compt;

	lst = ft_gotostart(lst);
	compt = 0;
	while (lst)
	{
		if (ft_lstisdir(lst, *opt) == 1 || ft_strcmp(lst->name, ".") ||
			ft_strcmp(lst->name, ".."))
			compt++;
		if (lst->next)
			lst = lst->next;
		else
			break ;
	}
	return (compt);
}

char	**ft_lst_to_char(t_file *lst, t_opt *option, int *compt)
{
	char	**arg;

	lst = ft_gotostart(lst);
	arg = (char **)malloc(sizeof(char *) * (*compt + 1));
	*compt = 0;
	while (lst)
	{
		if (lst->name && ft_lstisdir(lst, *option) &&
			!ft_lstishidden(lst->name, *option) &&
			!ft_rmv_dot(lst, option))
		{
			arg[*compt] = ft_strdup(lst->pathname);
			*compt += 1;
		}
		lst = lst->next;
	}
	arg[*compt] = NULL;
	return (arg);
}
