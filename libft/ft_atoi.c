/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:18:09 by vgrenier          #+#    #+#             */
/*   Updated: 2016/01/06 15:23:16 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		resultat;
	int		sign;
	int		i;

	i = 0;
	resultat = 0;
	sign = 1;
	while (str[i] > 0 && str[i] <= 32)
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && i != 20)
	{
		if (ft_isdigit(str[i]) == 0)
			return (resultat * sign);
		else
			resultat = resultat * 10 + str[i] - '0';
		i++;
	}
	if (i == 20)
		return (0);
	return (resultat * sign);
}
