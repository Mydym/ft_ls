/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstisdir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 13:45:34 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/23 13:49:29 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**Fonction qui renvoie un booleen : 1 si l'element est un dossier et ) sinon.
*/

int		ft_lstisdir(char *name)
{
	struct stat	filetype;

	if (stat(name, &filetype) != -1)
		if (S_ISDIR(filetype.st_mode))
			return (1);
	return (0);
}
