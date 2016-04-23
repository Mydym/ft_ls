/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreadarg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 14:13:58 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/23 16:18:49 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**Fonction pour recupere les arguments et leur type, et les classe
**avec sortal
*/

t_file		*ft_lstreadarg(char **larg)
{
	t_file		*plarg;
	int			i;

	plarg = NULL;
	i = -1;
	while (larg[++i])
	{
		if ((ft_lstisdir(larg[i]) == 1))
			ft_lstargsortal(&plarg, ft_lstfilenew(larg[i], 'd'));
		else
			ft_lstargsortal(&plarg, ft_lstfilenew(larg[i], '-'));
	}
	return (plarg);
}
