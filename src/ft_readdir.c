/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 10:35:45 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/10 17:19:11 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	*ft_readdir(const char *path, t_opt *opt, void (*psort)(t_file **,
			t_file *, t_opt *))
{
	t_file	*plst;
	t_file	*new;
	DIR		*rep;

	plst = NULL;
	if ((rep = ft_opendir(path)) != NULL)
	{
		while ((new = ft_lstreadfile(rep, (char *)path)) != NULL)
		{
			plst = ft_gotostart(plst);
			ft_putfilendl(new, opt);
			psort(&plst, new, opt);
		}
		closedir(rep);
	}
	plst = ft_gotostart(plst);
	return (plst);
}
