/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 14:22:52 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/10 11:56:01 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_init(t_opt *arg)
{
	arg->opt = 0;
	arg->tour = -1;
	return ;
}

int		ft_check_arg(char **arg, int i, t_opt option)
{
	if (arg[i + 1] && ft_strcmp(arg[i + 1], "--") == 0 && option.opt != 0)
		i++;
	else if (option.opt == 0 && ft_strcmp(arg[i + 1], "--") == 0)
		i += 2;
	else if (option.opt == 0)
		i++;
	return (i);
}

int		ft_option(char **arg, t_opt *new)
{
	int		i[2];

	i[0] = 1;
	ft_init(new);
	while (arg[i[0]] && arg[i[0]][0] == '-' && arg[i[0]][1] != '-')
	{
		i[1] = -1;
		while (arg[i[0]][++i[1]])
		{
			if (arg[i[0]][i[1]] == 'a')
				new->opt |= F_AMIN;
			else if (arg[i[0]][i[1]] == 'l')
				new->opt |= F_LMIN;
			else if (arg[i[0]][i[1]] == 'r')
				new->opt |= F_RMIN;
			else if (arg[i[0]][i[1]] == 'R')
				new->opt |= F_RMAJ;
			else if (arg[i[0]][i[1]] == 't')
				new->opt |= F_TMIN;
			else if (arg[i[0]][i[1]] != '-')
				return (ft_err_opt(arg[i[0]][i[1]]));
		}
		i[0]++;
	}
	return (ft_check_arg(arg, i[0] - 1, *new));
}
