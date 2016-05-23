/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreadarg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 14:13:58 by vgrenier          #+#    #+#             */
/*   Updated: 2016/05/23 14:00:58 by vgrenier         ###   ########.fr       */
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
	t_opt		*option;

	plarg = NULL;
	i = -1;
	option = NULL;
	ft_init(option);
	while (larg[++i])
	{
		if ((ft_lstisdir(larg[i], *option) == 1))
			ft_lstargsortal(&plarg, ft_lstfilenew(larg[i], 'd', "./"), option);
		else
			ft_lstargsortal(&plarg, ft_lstfilenew(larg[i], '-', "./"), option);
	}
	return (plarg);
}
