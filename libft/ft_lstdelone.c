/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 14:27:51 by vgrenier          #+#    #+#             */
/*   Updated: 2016/01/09 13:42:46 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (*alst)
		if ((*alst)->content)
		{
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = NULL;
		}
}
