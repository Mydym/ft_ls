/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 11:53:09 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/21 15:13:08 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
//	t_opt		option;
	int			i;

	i = 0;
	if (argc > 1)
	{
		/*if (argv[1][0] == '-')
		{
			option = ft_option(argv[1]);
			i = ft_recur1(&option, argv);
		}
		else*/
			ft_lstaffichdos(argv[1]);
	}
	else
		ft_lstaffichdos(".");
	return (0);
}