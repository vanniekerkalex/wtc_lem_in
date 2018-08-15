/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trial.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 15:25:34 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/15 21:45:07 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

int		ft_final_node(t_lem_in *lem, char *lst)
{
	lst = ft_strjoin(lst, "-");
	lst = ft_strjoin(lst, lem->rm[lem->rooms - 1].name);
	lem->lst = ft_strdup(lst);
	return (1);
}

int 	shortest_list(t_lem_in *lem, char *lst, int dir)
{
	//char *tmp;
	if (!dir) // 0 = right 1 = down
		while (lem->pos[0].x < lem->rooms)
		{
			if (lem->map[lem->pos[0].y][lem->pos[0].x] == 1)
			{
				lst = ft_strjoin(lst, "-");
				lst = ft_strjoin(lst, lem->rm[lem->pos[0].x].name);
				if((lem->map[lem->rooms - 1][lem->pos[0].x] == 1) ||
				(lem->map[lem->pos[0].y][lem->rooms - 1] == 1))
				{
					ft_final_node(lem, lst);
					break ;
				}
				lem->pos[0].y++;
				shortest_list(lem, lst, 1);
				break ;
			}
			lem->pos[0].x++;
		}
	else if (dir)
	{
		while (lem->pos[0].y < lem->rooms)
		{
			if (lem->map[lem->pos[0].y][lem->pos[0].x] == 1)
			{
				lst = ft_strjoin(lst, "-");
				lst = ft_strjoin(lst, lem->rm[lem->pos[0].y].name);
				if((lem->map[lem->rooms - 1][lem->pos[0].x] == 1) ||
				(lem->map[lem->pos[0].y][lem->rooms - 1] == 1))
				{
					ft_final_node(lem, lst);
					break ;
				}
				lem->pos[0].x++;
				shortest_list(lem, lst, 0);
				break ;
			}
			lem->pos[0].y++;
		}
	}
	if (lem->pos[0].x == lem->rooms - 1 || lem->pos[0].y == lem->rooms - 1)
	{
		lst = ft_strjoin(lst, "-");
		lst = ft_strjoin(lst, lem->rm[lem->rooms - 1].name);
		lem->lst = ft_strdup(lst);
		return (1);
	}
	return (0);
}

int 	ft_count_list_len(t_lem_in *lem)
{
	char **str;
	int len;

	str = ft_strsplit(lem->lst, '-');
	len = 0;
	while (*(str + len))
		len++;
	return (len);
}
