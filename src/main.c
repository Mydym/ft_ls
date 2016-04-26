/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 11:53:09 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/26 17:09:33 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**if (argc >= 2)
**	ft_lstafficharg(&argv[1]);
**else
**	ft_lstaffichdos(".");
*/

int		main(int argc, char **argv)
{
	t_opt		option;
	t_file		*plst;

	plst = NULL;
	if (argc > 1)
	{
		option = ft_option(argv);
		if (option.none == 0)
			plst = ft_recur1(&option, &argv[2], argc - 2);
		else
			plst = ft_recur1(&option, &argv[1], argc - 1);
		while (plst && plst->prev)
			plst = plst->prev;
		while (plst)
		{
			ft_putendl(plst->name);
			ft_putendl(&plst->type);
			plst = plst->next;
		}
	}
	else
	{
		ft_lstaffichdos(".");
	}
	return (0);
}
