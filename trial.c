/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trial.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 15:25:34 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/15 19:06:41 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

int		end_in_row(t_lem_in *lem, char *lst, int row)
{
	if (lem->map[row][lem->rooms - 1] == 1)
	{
		//add end to path
		write(1, "join", 4);
		lst = ft_strjoin(lst, "-");
		write(1, "join1", 5);
		lst = ft_strjoin(lst, lem->rm[lem->rooms - 1].name);
		write(1, "join2", 5);
		return (1);
	}
	return (0);
}

int 	shortest_list(t_lem_in *lem, char *lst, int dir)
{
	//char *tmp;

	if (lem->pos[0].x == lem->rooms - 1 || lem->pos[0].y == lem->rooms - 1)
	{
		lem->lst = ft_strdup(lst);
		return (1);
	}
	if (!dir) // 0 = right 1 = down
		while (lem->pos[0].x < lem->rooms)
		{
			if (end_in_row(lem, lst, lem->pos[0].y))
			{
				write(1, "IF", 2);
				return (0);
			}
			if (lem->map[lem->pos[0].y][lem->pos[0].x] == 1)
			{
				lst = ft_strjoin(lst, "-");
				lst = ft_strjoin(lst, lem->rm[lem->pos[0].x].name);
				lem->pos[0].y++;
				shortest_list(lem, lst, 1);
				break ;
			}
			lem->pos[0].x++;
		}
	else
	{
		while (lem->pos[0].y < lem->rooms)
		{
			if (end_in_row(lem, lst, lem->pos[0].y))
				return (0);
			if (lem->map[lem->pos[0].y][lem->pos[0].x] == 1)
			{
				lst = ft_strjoin(lst, "-");
				lst = ft_strjoin(lst, lem->rm[lem->pos[0].y].name);
				lem->pos[0].x++;
				shortest_list(lem, lst, 0);
				break ;
			}
			lem->pos[0].y++;
		}
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
