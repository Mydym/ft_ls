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

int		ft_lst_compt_elem(t_file *lst, t_opt *opt)
{
	int		compt;

	lst = ft_gotostart(lst);
	compt = 0;
	while (lst)
	{
		if (ft_lstishidden(lst->name, *opt) == 0)
			compt++;
		lst = lst->next;
	}
	return (compt);
}

char	**ft_lst_to_char(t_file *lst, t_opt *option, int *compt)
{
	char	**arg;

	lst = ft_gotostart(lst);
	*compt = ft_compt_lst(lst);
	arg = (char **)malloc(sizeof(char *) * (*compt + 1));
	arg[*compt] = NULL;
	*compt = 0;
	while (lst)
	{
		if (lst->name && ft_lstisdir(lst, *option) &&
			!ft_lstishidden(lst->name, *option) &&
			!ft_rmv_dot(lst, option))
		{
			arg[*compt] = lst->pathname;
			*compt += 1;
		}
		lst = lst->next;
	}
	return (arg);
}
