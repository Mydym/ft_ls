/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstishidden.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 16:38:04 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/09 15:56:57 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_rmv_dot(char *name, t_opt *opt)
{
	if (name)
		if (!(opt->opt & F_AMIN))
			if (ft_strcmp(name, ".") == 0 || ft_strcmp(name, "..") == 0)
				return (1);
	return (0);
}

int		ft_lstishidden(char *name, t_opt opt)
{
	if (name)
		if (!(opt.opt & F_AMIN))
			if (name[0] == '.')
				return (1);
	return (0);
}
