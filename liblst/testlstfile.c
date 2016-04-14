/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 15:20:46 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/14 16:55:25 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_file		*new;
	t_file		**plst;
	int			i;

	i = 1;
	if (argc > 1 && argc < 11)
	{
		if ((plst = (t_file **)malloc(sizeof(t_file *) * 11)) != NULL)
		{
			*plst = NULL;
			while (i < 10 && argv[i])
			{
				if ((new = ft_lstfilenew(argv[argc - i])) != NULL)
				{
					ft_lstfileadd(plst, new);
					ft_putnbr(i);
				}
				i++;
			}
			ft_lstfiledel(plst);
			while (*plst)
			{
				ft_putendl((*plst)->name);
				*plst = (*plst)->next;
			}
		}
	}
	return (0);
}
