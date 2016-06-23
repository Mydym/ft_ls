/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizemax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 12:44:31 by vgrenier          #+#    #+#             */
/*   Updated: 2016/05/26 15:19:27 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_maxinit(t_size *max)
{
	max->link = 0;
	max->user = 0;
	max->group = 0;
	max->taille = 0;
	max->maj = 0;
	max->min = 0;
}

static void	ft_getmajandmin(t_file *lst, t_size max)
{
	if (ft_intlen(lst->maj) > max.maj)
		max.maj = ft_intlen(lst->maj);
	if (ft_intlen(lst->min) > max.min)
		max.min = ft_intlen(lst->min);
}

static void	ft_get_max_grid(t_file *lst, t_size *max, t_opt *opt)
{
	int	user;
	int	group;

	user = -2;
	group = -2;
	if (lst->username && lst->groupname && !(opt->opt & F_NMIN))
	{
		user = (int)ft_strlen(lst->username);
		group = (int)ft_strlen(lst->groupname);
	}
	else if (opt->opt & F_NMIN)
	{
		user = ft_intlen(lst->userid);
		group = ft_intlen(lst->groupid);
	}
	if (user > max->user)
		max->user = user;
	if (group > max->group)
		max->group = group;
	return ;
}

t_size		ft_getmaxsize(t_file *lst, t_size max, t_opt *opt)
{
	while (lst)
	{
		ft_get_max_grid(lst, &max, opt);
		if (ft_intlen(lst->nblink) > max.link)
			max.link = ft_intlen(lst->nblink);
		if (ft_intlen(lst->size) > max.taille)
			max.taille = ft_intlen(lst->size);
		if (lst->maj != -1 || lst->min != -1)
			ft_getmajandmin(lst, max);
		lst = lst->next;
	}
	return (max);
}
