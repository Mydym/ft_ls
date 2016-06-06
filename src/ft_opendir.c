/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opendir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 13:32:50 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/06 17:44:47 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**Fonction pour ouvrir un dossier et renvoyer le pointeur sur DIR correspondant
*/

DIR	*ft_opendir(const char *file)
{
	DIR *repo;

	errno = 0;
	repo = opendir(file);
	if (repo)
		return (repo);
	else
		return (NULL);
}
