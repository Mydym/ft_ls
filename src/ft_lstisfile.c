/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstisfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:37:06 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/25 18:01:45 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_lstisfile(char *name)
{
	struct stat		test;

	if ((stat(name, &test) == 0) && !(S_ISDIR(test.st_mode)))
		return (1);
	return (0);
}
