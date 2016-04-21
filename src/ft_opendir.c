/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opendir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 13:32:50 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/13 13:32:52 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>

DIR	*ft_opendir(const char *file)
{
	DIR *repo;

	repo = opendir(file);
	if (repo)
		return (repo);
	else
		return (repo);
}
