/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viz.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 13:18:07 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/29 20:04:12 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	viz_heading(t_lem_in *lem, char **rooms)
{
	int i;

	i = 0;
	while (i < lem->len)
	{
		mvprintw(0, i * 10, rooms[i]);
		i++;
	}
	i = 0;
	while (i < (lem->len - 1) * 10)
		mvprintw(1, i++, "-");
}

void	viz_move(t_lem_in *lem, int color, int room, int ant)
{
	int k;

	if (room <= -2 || ant >= lem->ants || room >= lem->len + lem->ants - 2)
		return ;
	k = 0;
	while (k <= 10)
	{
		if (room < lem->len - 1)
		{
			attron(COLOR_PAIR(color));
			mvprintw(1, (room * 10) + k, "X");
			if (k > 0)
			{
				attron(COLOR_PAIR(4));
				mvprintw(1, (room * 10) + k - 1, "-");
			}
			refresh();
			usleep(500000 / lem->ants);
		}
		k++;
	}
	if (room < lem->len + lem->ants - 2)
		viz_move(lem, (color + 1) % 3 + 1, room - 1, ant + 1);
	return ;
}
void	viz_ants(t_lem_in *lem)
{
	int i;

	i = 0;
	while (i < lem->ants * lem->len + 1)
	{
		viz_move(lem, 0 % 3 + 1, i, 0);
		i++;
	}
}

void	viz(t_lem_in *lem)
{
	char **rooms;
	int i;

	i = 0;
	rooms = ft_strsplit(lem->lst, '-');
	curs_set(0);
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_WHITE, COLOR_BLACK);
	attron(COLOR_PAIR(4));
	viz_heading(lem, rooms);
	viz_ants(lem);
	//refresh();
	//usleep(300000);
	clear();
}
