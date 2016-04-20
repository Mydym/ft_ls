/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfilenew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 16:14:00 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/20 13:23:24 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

t_file		*ft_lstfilenew(char *filename)
{
	t_file		*new;

	if ((new = (t_file *)malloc(sizeof(t_file))) == NULL)
		return (NULL);
	if (filename == NULL)
		new->name = NULL;
	else
		new->name = filename;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
