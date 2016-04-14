/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 15:08:02 by vgrenier          #+#    #+#             */
/*   Updated: 2016/04/14 17:25:33 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../libft/libft.h"
# include <dirent.h>
# include <sys/types.h>

typedef struct		s_file
{
	char			*name;
	dev_t			type;
	mode_t			perm;
	nlink_t			nblink;
	uid_t			iduser;
	char			*username;
	gid_t			idgroup;
	char			*groupname;
	off_t			size;
	time_t			mtime;
	struct s_file	*prev;
	struct s_file	*next;
}					t_file;
void				ft_straffichdos(char *path);
char				**ft_strreaddir(const char *file);
char				*ft_strreadfile(DIR *dirp);
DIR					*ft_opendir(const char *file);
t_file				*ft_lstreadfile(DIR *dirp);
t_file				**ft_lstreaddir(const char *file);
void				ft_lstaffichdos(char *path);
void				ft_lstfileadd(t_file **plst, t_file *new);
void				ft_lstfiledel(t_file **plst);
t_file				*ft_lstfiledelone(t_file **plst);
t_file				*ft_lstfiledelend(t_file **plst);
t_file				*ft_lstfilenew(char *filename);

#endif
