/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 15:08:02 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/11 18:21:52 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <struct.h>
# include <prepro.h>

void	ft_ls(int argc, char **arg);

t_file	*ft_recurarg(t_opt *option, char **larg, int k, int i);
void	ft_recurfile(t_file *lstarg, t_opt *option, int k, int i);

DIR		*ft_opendir(const char *file, t_opt *opt);
t_file	*ft_readdir(const char *path, t_opt *opt,
		void (*psort)(t_file **, t_file *, t_opt *));
t_file	*ft_lstreadfile(DIR *dirp, char *repo, t_opt *opt);

void	ft_lstargsortal(t_file **larg, t_file *elem, t_opt *option);
void	ft_lstargsorttime(t_file **larg, t_file *elem, t_opt *option);
char	**ft_alsort_arg(char **arg);

t_file	*ft_lstfilenew(char *filename, char type, char *path);
void	ft_lstfileadd(t_file **plst, t_file *new);
void	ft_lstfileaddend(t_file **plst, t_file *new);
t_file	*ft_lstfiledelone(t_file **plst);
void	ft_lstfiledel(t_file **plst);

char	**ft_lst_to_char(t_file *lst, t_opt *option, int *compt);
int		ft_lst_compt_dir(t_file *lst, t_opt *opt);
int		ft_compt_lst(t_file *plst);

t_file	*ft_gotostart(t_file *lst);
t_file	*ft_gotoend(t_file *lst);
t_file	*ft_gotofileend(t_file *lst);

void	ft_lstfindtype(t_file *elem);
int		ft_charisdir(char *name, t_opt option);
int		ft_lstisdir(t_file *elem, t_opt option);
int		ft_lstishidden(char *name, t_opt opt);
int		ft_rmv_dot(t_file *file, t_opt *opt);
int		ft_lstisfile(char *name);

void	ft_permuser(struct stat detail, t_file *file);
void	ft_permgroup(struct stat detail, t_file *file);
void	ft_permother(struct stat detail, t_file *file);
void	ft_permglobal(t_file *file);
void	ft_getfiledetail(t_file *file);
int		ft_putfilendl(t_file *file, t_opt *option);
int		ft_gettime(t_file *plst, t_opt *option);

void	ft_error(char *name, t_opt *opt);
int		ft_err_opt(char c);

void	ft_printdosname(t_file *elem, t_opt *option);
void	ft_putdetail(t_file *file, t_opt *option, t_size max);
void	ft_puttotal(t_file *elem, t_opt option);

char	**ft_split_ar_op(char **arg, t_opt *new);

void	ft_maxinit(t_size *max);
t_size	ft_getmaxsize(t_file *lst, t_size max);

//Libft :
int		ft_ppchar_nb_str(char **str);

#endif
