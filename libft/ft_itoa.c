/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:14:27 by vgrenier          #+#    #+#             */
/*   Updated: 2015/12/06 20:25:18 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_nbint(int n)
{
	int				nb;

	nb = 0;
	if (n <= 0)
		nb++;
	while (n != 0)
	{
		n /= 10;
		nb++;
	}
	return (nb);
}

char		*ft_itoa(int n)
{
	int				i;
	int				nb;
	unsigned int	n2;
	char			*str;

	nb = ft_nbint(n);
	n2 = (unsigned int)n;
	str = (char *)malloc((nb + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	str[nb] = 0;
	if (n < 0)
	{
		str[0] = '-';
		n2 *= -1;
		i++;
	}
	while (i < nb--)
	{
		str[nb] = n2 % 10 + '0';
		n2 /= 10;
	}
	return (str);
}
