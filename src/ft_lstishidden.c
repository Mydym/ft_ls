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

int		ft_rmv_dot(t_file *file, t_opt *opt)
{
	if (!(opt->opt & F_AMIN))
		if (file->name)
			if (!ft_strcmp(file->name, ".") || !ft_strcmp(file->name, ".."))
				return (1);
	return (0);
}

int		ft_lstishidden(char *name, t_opt opt)
{
	if (!(opt.opt & F_AMIN) && !(opt.opt & F_DMIN))
		if (name)
			if (name[0] == '.')
				return (1);
	return (0);
}
