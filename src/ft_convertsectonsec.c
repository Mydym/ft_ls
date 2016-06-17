/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertsectonsec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 16:07:41 by vgrenier          #+#    #+#             */
/*   Updated: 2016/05/05 16:07:52 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long	ft_convertsectonsec(unsigned long long sec)
{
	int		k;

	k = 9;
	while (k-- != 0)
		sec *= 10;
	return (sec);
}
