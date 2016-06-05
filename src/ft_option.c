/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 14:22:52 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/05 19:22:31 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_init(t_opt *arg)
{
	arg->opt = 0;
	return ;
}

int		ft_option(char **arg, t_opt *new)
{
	int		i;
	int		j;

	j = 1;
	new->opt = 0;
	while (arg[j] && arg[j][0] == '-' && arg[j][1] != '-')
	{
		i = 0;
		while (arg[j][i])
		{
			if (arg[j][i] == 'a')
				new->opt |= F_AMIN;
			if (arg[j][i] == 'l')
				new->opt |= F_LMIN;
			if (arg[j][i] == 'r')
				new->opt |= F_RMIN;
			if (arg[j][i] == 'R')
				new->opt |= F_RMAJ;
			if (arg[j][i] == 't')
				new->opt |= F_TMIN;
			i++;
		}
		j++;
	}
	return (j - 1);
}
