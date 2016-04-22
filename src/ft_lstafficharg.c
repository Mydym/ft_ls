/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstafficharg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 16:48:40 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/22 17:31:04 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**Fonction pour recuperer les arguments et leur type avec lstreadarg
**Puis les afficher selon leur type avec lstcheckarg
*/

void	ft_lstafficharg(char **arg)
{
	t_file	*larg;

	if ((larg = ft_lstreadarg(arg)))
	{
		while (larg->prev)
			larg = larg->prev;
		ft_lstcheckarg(&larg);
	}
}
