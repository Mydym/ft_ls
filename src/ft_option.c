/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 14:22:52 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/04 16:34:24 by vgrenier         ###   ########.fr       */
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

int		ft_option(char **arg, t_opt *new)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	ft_init(new);
	while (arg[j][0] == '-')
	{
		while (arg[j][i])
		{
			if (arg[j][i] == 'a')
				new->a = 1;
			if (arg[j][i] == 'l')
				new->l = 1;
			if (arg[j][i] == 'r')
				new->r = 1;
			if (arg[j][i] == 'R')
				new->gr = 1;
			if (arg[j][i] == 't')
				new->t = 1;
			if (new->a == 1 || new->l == 1 || new->r == 1 || new->t == 1 ||
					new->gr == 1)
				new->none = 0;
			i++;
		}
		i = 0;
		j++;
	}
	return (j);
}
