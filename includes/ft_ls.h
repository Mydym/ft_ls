/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 15:08:02 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/22 16:50:39 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../lib/libft/libft.h"
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_file
{
	char			*name;
	char			type;
	char			*perm;
	int				nblink;
	char			*username;
	char			*groupname;
	int				size;
	int				mtime;
	char			*formattime;
	struct s_file	*prev;
	struct s_file	*next;
}					t_file;

typedef struct		s_opt
{
	int		none;
	int		a;
	int		l;
	int		r;
	int		gr;
	int		t;
}					t_opt;

int					ft_recur1(t_opt *option, char **larg);
t_opt				ft_option(char *arg);
DIR					*ft_opendir(const char *file);
void				ft_filestat(t_file *elem);
void				ft_lstfilesortal(t_file **plst, t_file *elem);
void				ft_lstfilesorttime(t_file **plst, t_file *elem);
t_file				*ft_lstreadarg(char **larg);
t_file				*ft_lstreadfile(DIR *dirp);
t_file				*ft_lstreaddir(const char *file);
void				ft_lstaffichdos(char *path);
void				ft_lstfileadd(t_file **plst, t_file *new);
void				ft_lstfileaddend(t_file **plst, t_file *new);
void				ft_lstfiledel(t_file **plst);
t_file				*ft_lstfiledelone(t_file **plst);
t_file				*ft_lstfiledelend(t_file **plst);
t_file				*ft_lstfilenew(char *filename, char type);
t_file				*ft_lstfindtype(char *name);
void				ft_lstcheckarg(t_file **larg);
void				ft_lstafficharg(char **arg);

#endif
