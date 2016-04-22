/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreadarg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 14:13:58 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/22 17:18:36 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**Fonction pour recupere les arguments et leur type, et les classe avec sortal
*/

t_file		*ft_lstreadarg(char **larg)
{
	t_file		*plarg;
	t_file		*elem;
	int			i;

	plarg = NULL;
	i = -1;
	while (larg[++i])
		if ((elem = ft_lstfindtype(larg[i])))
			ft_lstfilesortal(&plarg, elem);
	return (plarg);
}
