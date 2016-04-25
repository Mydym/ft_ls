/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opendir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 13:32:50 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/25 17:31:11 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
		return (NULL);
}
