/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 19:04:49 by vgrenier          #+#    #+#             */
/*   Updated: 2016/01/09 16:43:32 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*map;

	if (!(map = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	map = f(map);
	if (lst->next)
		map->next = ft_lstmap(lst->next, f);
	return (map);
}
