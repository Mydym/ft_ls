/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstisdir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 13:45:34 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/05 15:02:21 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**Fonction qui renvoie un booleen : 1 si l'element est un dossier et 0 sinon.
*/

int		ft_charisdir(char *name, t_opt option)
{
	struct stat		type;

	if ((lstat(name, &type)) == 0)
	{
		if (S_ISDIR(type.st_mode))
			return (1);
		else if (S_ISLNK(type.st_mode) && (!(option.opt & F_LMIN)))
			return (1);
	}
	return (0);
}

int		ft_lstisdir(t_file *elem, t_opt option)
{
	struct stat		type;

	if ((lstat(elem->pathname, &type)) == 0)
	{
		if (S_ISDIR(type.st_mode))
			return (1);
		else if (S_ISLNK(type.st_mode) && (!(option.opt & F_LMIN)))
			return (1);
	}
	return (0);
}
