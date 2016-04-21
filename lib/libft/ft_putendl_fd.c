/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 17:38:28 by vgrenier          #+#    #+#             */
/*   Updated: 2015/12/06 20:49:00 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putendl_fd(const char *s, int fd)
{
	int		len;

	len = ft_strlen(s);
	if (fd != -1)
	{
		write(fd, s, len);
		write(fd, "\n", 1);
	}
}
