/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 14:05:02 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/29 17:17:17 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_ls(int argc, char **arg)
{
	t_opt		option;
	t_file		*plst;

	plst = NULL;
	if (argc > 1)
	{
		option = ft_option(arg);
		if (option.none == 0)
			plst = ft_recurarg(&option, &arg[2], argc - 2, argc - 2);
		else
			plst = ft_recurarg(&option, &arg[1], argc - 1, argc - 1);
	}
}

t_file		*ft_gotostart(t_file *lst)
{
	while (lst && lst->prev)
		lst = lst->prev;
	return (lst);
}
