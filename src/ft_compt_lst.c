/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conpt_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:20:07 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/08 18:21:01 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_compt_lst(t_file *plst)
{
	int	k;

	k = 1;
	plst = ft_gotostart(plst);
	while (plst && plst->next && (plst = plst->next))
		k++;
	return (k);
}
