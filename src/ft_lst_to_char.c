/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 16:44:49 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/03 16:47:35 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_lst_compt_elem(t_file *lst)
{
	int		compt;

	lst = ft_gotostart(lst);
	compt = 0;
	while (lst)
	{
		compt++;
		lst = lst->next;
	}
	return (compt);
}

char	**ft_lst_to_char(t_file *lst, t_opt *option)
{
	int		compt;
	char	**arg;

	lst = ft_gotostart(lst);
	compt = ft_lst_compt_elem(lst);
	arg = (char **)malloc(sizeof(char *) * (compt + 1));
	arg[compt] = NULL;
	compt = 0;
	while (lst)
	{
		if (lst->name && ft_lstisdir(lst, *option) == 1)
		{
			arg[compt] = lst->pathname;
			compt++;
		}
		lst = lst->next;
	}
	return (arg);
}
