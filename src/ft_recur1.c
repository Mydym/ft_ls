/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recur1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 14:10:14 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/22 14:04:29 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_recur1(t_opt *option, char **larg)
{
	void	(*psort)(void);
	t_file	*plst;

	if (option->t == 0)
		psort = ft_lstfilesortal;
	else
		psort = ft_lstfilesorttime;
	plst = ft_lstreadarg(larg);
	plst = ft_lstreaddir(larg[1]);
	return (0);
}
