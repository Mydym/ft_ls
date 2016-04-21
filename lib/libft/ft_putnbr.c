/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:04:09 by vgrenier          #+#    #+#             */
/*   Updated: 2015/11/30 19:25:13 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		if (n < -9)
			ft_putnbr((0 - (unsigned int)n) / 10);
		ft_putchar((n % 10) * -1 + '0');
	}
	else
		ft_putchar(n + '0');
}
