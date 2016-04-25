/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_badname.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:48:07 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/25 17:49:26 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_badname(char *name)
{
	ft_putstr("./ft_ls: ");
	ft_putstr(name);
	ft_putendl(": No such file or directory");
}
