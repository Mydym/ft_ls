/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:14:22 by vgrenier          #+#    #+#             */
/*   Updated: 2015/12/06 20:33:25 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int					i;
	const unsigned char *str1;
	const unsigned char *str2;

	i = 0;
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while (str1[i] && str1[i] == str2[i] && str2[i])
		i++;
	return (str1[i] - str2[i]);
}
