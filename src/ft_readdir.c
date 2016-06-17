/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 10:35:45 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/11 17:06:18 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	*ft_readdir(const char *path, t_opt *opt, void (*psort)(t_file **,
			t_file *, t_opt *))
{
	t_file	*plst;
	t_file	*new;
	DIR		*rep;
	int		res;

	plst = NULL;
	res = 0;
	if ((rep = ft_opendir(path)) != NULL)
	{
		while ((new = ft_lstreadfile(rep, (char *)path)) != NULL)
		{
			plst = ft_gotostart(plst);
			if (!ft_lstishidden(new->name, *opt) && !ft_rmv_dot(new, opt)
				&& (res = ft_putfilendl(new, opt)) == 0)
				psort(&plst, new, opt);
			else
				ft_lstfiledelone(&new);
		}
		closedir(rep);
	}
	plst = ft_gotostart(plst);
	if (res == 0)
		return (plst);
	errno = 13;
	return (NULL);
}
