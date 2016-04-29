/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 15:08:02 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/29 13:13:56 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../lib/libft/libft.h"
# include <dirent.h>
# include <time.h>
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

void				ft_ls(int argc, char **arg);
void				ft_lstprintarg(t_file *lst);
t_file				*ft_recurarg(t_opt *option, char **larg, int k, int i);
void				ft_recurfile(t_file *lstarg, t_opt *option);
void				ft_recurdos(char *doss, t_opt *option);
t_opt				ft_option(char **arg);
DIR					*ft_opendir(const char *file);
void				ft_filestat(t_file *elem);
void				ft_lstfilesortal(t_file **plst, t_file *elem);
void				ft_lstargsortal(t_file **larg, t_file *elem);
void				ft_lstfilesorttime(t_file **plst, t_file *elem);
void				ft_lstargsorttime(t_file **larg, t_file *elem);
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
void				ft_printdosname(char *name, char *space);
void				ft_verifaffich(t_file *larg);
int					ft_lstisdir(char *name);
int					ft_lstisfile(char *name);
int					ft_lstishidden(char *name);
void				ft_badname(char *name);
t_file				*ft_gotostart(t_file *lst);

#endif
