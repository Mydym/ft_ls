/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 16:44:49 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/05 15:09:11 by vgrenier         ###   ########.fr       */
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
		if (ft_lstishidden(lst->name) == 0)
			compt++;
		lst = lst->next;
	}
	return (compt);
}

char	**ft_lst_to_char(t_file *lst, t_opt *option, int *compt)
{
	char	**arg;

	lst = ft_gotostart(lst);
	*compt = ft_lst_compt_elem(lst);
	arg = (char **)malloc(sizeof(char *) * (*compt + 1));
	arg[*compt] = NULL;
	*compt = 0;
	while (lst)
	{
		if (lst->name && ft_lstisdir(lst, *option) == 1 &&
				(ft_lstishidden(lst->name) == 0 || (option->opt & F_AMIN &&
				lst->name[0] != '.' && lst->name[1] != '\0')))
		{
			arg[*compt] = lst->pathname;
			*compt += 1;
		}
		lst = lst->next;
	}
	return (arg);
}
