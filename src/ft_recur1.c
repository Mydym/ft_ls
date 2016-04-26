/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recur1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 14:10:14 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/26 16:05:06 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*ft_recur1(t_opt *option, char **larg, int k)
{
	void	(*psort)(t_file **, t_file *);
	t_file	*elem;
	t_file	*new;

	elem = NULL;
	new = NULL;
	if (option->t)
		psort = &ft_lstargsorttime;
	else
		psort = &ft_lstargsortal;
	if (--k > 0)
		new = ft_recur1(option, larg, k);
	if (larg[k])
	{
		if ((ft_lstisdir(larg[k])))
			elem = ft_lstfilenew(larg[k], 'd');
		else if ((ft_lstisfile(larg[k])))
			elem = ft_lstfilenew(larg[k], '-');
		else
			ft_badname(larg[k]);
	}
	if (elem)
		psort(&new, elem);
	return (new);
}
