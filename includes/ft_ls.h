/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 15:08:02 by vgrenier          #+#    #+#             */
/*   Updated: 2016/05/12 18:51:58 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../lib/libft/libft.h"
# include <dirent.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>

# define SEC_TO_NSEC ft_convertsectonsec(plst->mtime)

typedef struct		s_file
{
	char				*path;
	char				*pathname;
	char				*name;
	char				type;
	char				*permus;
	char				*permgp;
	char				*permoth;
	char				*perm;
	int					nblink;
	char				*username;
	char				*groupname;
	int					size;
	unsigned long long	mtime;
	unsigned long long	mtimenano;
	char				*formattime;
	struct s_file		*prev;
	struct s_file		*next;
}					t_file;

typedef struct		s_size
{
	int		link;
	int		user;
	int		group;
	int		taille;
}					t_size;

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
t_file				*ft_recurarg(t_opt *option, char **larg, int k, int i);
void				ft_recurfile(t_file *lstarg, t_opt *option, int x);
void				ft_recurfilerev(t_file *lstarg, t_opt *option, int first, t_size max);
void				ft_recurdos(char *doss, t_opt *option);
t_opt				ft_option(char **arg);
void				ft_init(t_opt *arg);
DIR					*ft_opendir(const char *file);
void				ft_filestat(t_file *elem);
void				ft_lstfilesortal(t_file **plst, t_file *elem, t_opt *option);
void				ft_lstargsortal(t_file **larg, t_file *elem, t_opt *option);
void				ft_lstsorttimenano(t_file **larg, t_file *elem);
void				ft_lstfilesorttime(t_file **plst, t_file *elem, t_opt *option);
void				ft_lstargsorttime(t_file **larg, t_file *elem, t_opt *option);
t_file				*ft_lstreadarg(char **larg);
t_file				*ft_lstreadfile(DIR *dirp, char *repo);
t_file				*ft_lstreaddir(const char *file);
void				ft_lstaffichdos(char *path);
void				ft_lstfileadd(t_file **plst, t_file *new);
void				ft_lstfileaddend(t_file **plst, t_file *new);
void				ft_lstfiledel(t_file **plst);
t_file				*ft_lstfiledelone(t_file **plst);
t_file				*ft_lstfiledelend(t_file **plst);
t_file				*ft_lstfilenew(char *filename, char type, char *path);
void				ft_lstfindtype(t_file *elem);
void				ft_lstcheckarg(t_file **larg);
void				ft_lstafficharg(char **arg);
void				ft_printdosname(t_file *elem, char *space);
void				ft_verifaffich(t_file *larg);
int					ft_lstisdir(char *name);
int					ft_lstisfile(char *name);
int					ft_lstishidden(char *name);
void				ft_badname(char *name);
t_file				*ft_gotostart(t_file *lst);
t_file				*ft_gotoend(t_file *lst);
t_file				*ft_gotofileend(t_file *lst);
void				ft_printrevdos(t_file *lst, int first, t_opt *option);
void				ft_lstprintarg(t_file *lst);
void				ft_putfilendl(t_file *file, t_opt *option);
void				ft_permuser(struct stat detail, t_file *file);
void				ft_permgroup(struct stat detail, t_file *file);
void				ft_permother(struct stat detail, t_file *file);
void				ft_permglobal(t_file *file);
int					ft_gettime(t_file *plst, t_opt *option);
void				ft_stocktime(t_file *plst, struct stat m_time, t_opt *option);
unsigned long long	ft_convertsectonsec(unsigned long long sec);
void				ft_getfiledetail(t_file *file);
void				ft_putdetail(t_file *file, t_opt *option, t_size max);
void				ft_stockfiledetail(t_file *file, struct stat detail);
int					ft_intlen(int nombre);
void				ft_maxinit(t_size *max);
t_size				ft_getmaxsize(t_file *lst);

#endif
