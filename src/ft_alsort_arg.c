/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alsort_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <vgrenier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 17:41:44 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/18 17:41:44 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**ft_alsort_arg(char **arg)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (arg[i])
	{
		j = 1;
		while (arg[j] && arg[j + 1])
		{
			if (ft_strcmp(arg[j], arg[j + 1]) > 0)
			{
				s = arg[j];
				arg[j] = arg[j + 1];
				arg[j + 1] = s;
			}
			j++;
		}
		i++;
	}
	return (arg);
}
