/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepro.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <vgrenier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 22:13:33 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/22 22:13:33 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PREPRO_H
# define PREPRO_H

# include "../libft/libft.h"
# include <dirent.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>

# define STDERR_FD 2
# define PROG_NAME "ft_ls"
# define LEN_NAME 5

# define OPTRMAJ (opt->opt & F_RMAJ)

# define SEC_TO_NSEC ft_convertsectonsec(plst->mtime)

# define BSHL(x,y) ((x) << (y))
# define B(x) BSHL(1,(x))

# define F_LMIN B(0)
# define F_AMIN B(1)
# define F_RMIN B(2)
# define F_TMIN B(3)
# define F_RMAJ B(4)
# define F_TMAJ B(5)
# define F_DMIN B(6)
# define F_NMIN B(7)
# define F_ERR_EX B(30)

#endif
