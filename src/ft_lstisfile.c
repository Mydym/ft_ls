/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstisfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:37:06 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/01 13:18:59 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_lstisfile(char *name, t_opt *opt)
{
	struct stat		test;
	int				i;

	if (((i = lstat(name, &test)) == 0) && (!(S_ISDIR(test.st_mode))
		|| ft_strcmp(name, ".") || ft_strcmp(name, "..")))
		return (1);
	else if (i == 0 && (opt->opt & F_DMIN))
		return (1);
	return (0);
}
