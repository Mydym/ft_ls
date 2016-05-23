/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstisdir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 13:45:34 by vgrenier          #+#    #+#             */
/*   Updated: 2016/05/23 13:59:40 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**Fonction qui renvoie un booleen : 1 si l'element est un dossier et 0 sinon.
*/

int		ft_lstisdir(char *name, t_opt option)
{
	struct stat		type;

	if ((lstat(name, &type)) == 0)
	{
		if (S_ISDIR(type.st_mode))
			return (1);
		else if (S_ISLNK(type.st_mode) && option.l == 0)
			return (1);
	}
	return (0);
}
