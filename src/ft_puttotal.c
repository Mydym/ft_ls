/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttotal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 15:45:02 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/11 13:41:03 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_puttotal(t_file *elem, t_opt option)
{
	int		total;
	int		compt;

	total = 0;
	compt = 0;
	if (option.opt & F_LMIN)
	{
		while (elem)
		{
			total += elem->sblock;
			compt++;
			elem = elem->next;
		}
		if (compt != 0)
		{
			ft_putstr("total ");
			ft_putnbr(total);
			ft_putchar('\n');
		}
	}
	return ;
}
