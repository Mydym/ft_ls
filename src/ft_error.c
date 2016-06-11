/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 15:05:50 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/11 16:35:51 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_err_opt(char c)
{
	write(STDERR_FD, PROG_NAME, LEN_NAME);
	write(STDERR_FD, ": illegal option -- ", 20);
	write(STDERR_FD, &c, 1);
	write(STDERR_FD, "\nusage: ", 8);
	write(STDERR_FD, PROG_NAME, LEN_NAME);
	write(STDERR_FD, " [-Ralrt] [file ...]\n", 21);
	return (-1);
}

void		ft_error(char *name)
{
	char	*strerr;

	strerr = strerror(errno);
	write(STDERR_FD, PROG_NAME, LEN_NAME);
	write(STDERR_FD, ": ", 2);
	write(STDERR_FD, name, ft_strlen(name));
	write(STDERR_FD, ": ", 2);
	write(STDERR_FD, strerr, ft_strlen(strerr));
	write(STDERR_FD, "\n", 1);
	return ;
}
