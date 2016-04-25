/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstisdir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 13:45:34 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/25 17:33:54 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**Fonction qui renvoie un booleen : 1 si l'element est un dossier et 0 sinon.
*/

int		ft_lstisdir(char *name)
{
	DIR *doc;

	if ((doc = ft_opendir(name)) != NULL)
	{
		closedir(doc);
		return (1);
	}
	return (0);
}
