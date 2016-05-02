/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verifaffich.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 15:16:51 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/29 13:51:19 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_verifaffich(t_file *larg)
{
	if (larg->type == '-')
		ft_putendl(larg->name);
	else
	{
		if (larg->prev)
			ft_putendl("");
		if (larg->prev)
			ft_printdosname(larg->name, "\n");
		else if (larg->next)
			ft_printdosname(larg->name, "");
		ft_lstaffichdos(larg->name);
	}
}