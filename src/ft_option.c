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

static void		ft_init(t_opt *arg)
{
	arg->opt = 0;
	arg->tour = -1;
	return ;
}

static int		ft_check_op(char c, t_opt *new)
{
	if (c == 'a')
		new->opt |= F_AMIN;
	else if (c == 'r')
		new->opt |= F_RMIN;
	else if (c == 'R')
		new->opt |= F_RMAJ;
	else if (c == 't')
		new->opt |= F_TMIN;
	else if (c == 'T')
		new->opt |= F_TMAJ;
	else if (c == 'd')
		new->opt |= F_DMIN;
	else if (c == 'n')
	{
		new->opt |= F_NMIN;
		new->opt |= F_LMIN;
	}
	else if (c == 'l')
		new->opt |= F_LMIN;
	else if (c == '1')
		new->opt &= ~F_LMIN;
	else
		return (1);
	return (0);
}

static int		ft_option(char **arg, t_opt *new)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (arg[++i] && arg[i][0] == '-' && ft_strcmp(arg[i], "--"))
	{
		j = -1;
		while (arg[i][++j])
		{
			k = ft_check_op(arg[i][j], new);
			if (k == 1 && (arg[i][j] != '-' || j != 0))
				return (ft_err_opt(arg[i][j]));
			else if (k == 1 && !arg[i][j + 1])
				return (i);
		}
	}
	return (i);
}

char			**ft_split_ar_op(char **arg, t_opt *new)
{
	int		ind;

	ft_init(new);
	ind = ft_option(arg, new);
	if (ind == -1)
		exit(EXIT_FAILURE);
	if (arg[ind] && !ft_strcmp(arg[ind], "--") && arg[ind + 1])
		return (&arg[ind + 1]);
	else if (arg[ind] && !ft_strcmp(arg[ind], "--") && !arg[ind + 1])
		return (NULL);
	else if (arg[ind])
		return (&arg[ind]);
	else
		return (NULL);
}
