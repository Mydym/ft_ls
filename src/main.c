/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 11:53:09 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/20 19:08:19 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (argv[1][0] == '-')
			ft_option(argv[1]);
		else
			ft_lstaffichdos(argv[1]);
	}
	else
		ft_lstaffichdos(".");
	return (0);
}
