/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 14:22:52 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/22 17:31:03 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_init(t_opt *arg)
{
	arg->none = 1;
	arg->a = 0;
	arg->l = 0;
	arg->r = 0;
	arg->t = 0;
	arg->gr = 0;
	return ;
}

t_opt	ft_option(char *arg)
{
	t_opt	new;
	int		i;

	i = 0;
	ft_init(&new);
	if (arg[0] == '-')
		while (arg[i])
		{
			if (arg[i] == 'a')
				new.a = 1;
			if (arg[i] == 'l')
				new.l = 1;
			if (arg[i] == 'r')
				new.r = 1;
			if (arg[i] == 'R')
				new.gr = 1;
			if (arg[i] == 't')
				new.t = 1;
			if (new.a == 1 || new.l == 1 || new.r == 1 || new.t == 1 ||
					new.gr == 1)
				new.none = 0;
			i++;
		}
	return (new);
}
