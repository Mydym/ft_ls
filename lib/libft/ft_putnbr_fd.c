/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 17:41:56 by vgrenier          #+#    #+#             */
/*   Updated: 2015/12/06 20:32:07 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		if (n < -9)
			ft_putnbr_fd((0 - (unsigned int)n) / 10, fd);
		c = (n % 10) * -1 + '0';
		write(fd, &c, 1);
	}
	else
	{
		c = n + '0';
		write(fd, &c, 1);
	}
}
