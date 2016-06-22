/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <vgrenier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 22:04:20 by vgrenier          #+#    #+#             */
/*   Updated: 2016/06/22 22:04:20 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

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
	int					groupid;
	int					maj;
	int					min;
	unsigned long		size;
	unsigned long		sblock;
	long long			mtime;
	long long			mtimenano;
	char				*formattime;
	struct s_file		*prev;
	struct s_file		*next;
}					t_file;

typedef struct		s_size
{
	int		link;
	int		user;
	int		group;
	long	taille;
	int		maj;
	int		min;
}					t_size;

typedef struct		s_opt
{
	int				opt;
	int				tour;
}					t_opt;

#endif
