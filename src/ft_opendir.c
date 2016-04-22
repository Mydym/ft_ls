/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opendir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 13:32:50 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/22 17:30:52 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>

/*
**Fonction pour ouvrir un dossier et renvoyer le pointeur sur DIR correspondant
*/

DIR	*ft_opendir(const char *file)
{
	DIR *repo;

	repo = opendir(file);
	if (repo)
		return (repo);
	else
		return (repo);
}
