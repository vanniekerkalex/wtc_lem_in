/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viz.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 13:18:07 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/29 16:40:38 by avan-ni          ###   ########.fr       */
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
	while (i <= (lem->len - 1) * 10)
		mvprintw(1, i++, "-");
}

void	viz_ants(t_lem_in *lem)//, char **rooms)
{
	int i;
	int j;
	int k;
	int l;

	i = 0;
	l = 0;
	while (i < (lem->len - 1) * 10)//lem->ants * ((lem->len * 10) - 19))
	{
		j = l;
		while (j >= 0)
		{
			//attron(COLOR_PAIR(j % 3 + 1));
			k = 0;
			while (k < 10)
			{
				attron(COLOR_PAIR((j % 10) % 3 + 1));
				if (k % 10)
					mvprintw(1, (j * 10) + k, "X");
				k++;
				refresh();
				usleep(100000);
			}
			j--;
		}
		l++;
		i+= 10;
		refresh();
		usleep(300000);
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
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_WHITE, COLOR_BLACK);
	attron(COLOR_PAIR(4));

	viz_heading(lem, rooms);
	viz_ants(lem);//, rooms);


	refresh();
	usleep(300000);
	clear();
}



/*
void	ft_print_arr(t_stacks *s, int x, int y)
{
	int i;
	int j;

	i = s->len_a - 1;
	j = 0;
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_WHITE, COLOR_BLACK);
	mvprintw(y + j, x, "TOP OF A\n");
	mvprintw(y + j + 1, x, "---\n");
	mvprintw(y + j, x + 20, "TOP OF B\n");
	mvprintw(y + j + 1, x + 20, "---\n");
	j += 2;
	attron(COLOR_PAIR(1));
	while (i >= 0)
		(j <= 84) ? (mvprintw(y + j++, x, "%d\n", s->stack_a[i--])) : (i--);
	i = s->len_b - 1;
	j = 2;
	attron(COLOR_PAIR(2));
	while (i >= 0)
		(j <= 84) ? (mvprintw(y + j++, x + 20, "%d\n",
					s->stack_b[i--])) : (i--);
	attron(COLOR_PAIR(3));
}

void	print_win(t_stacks *s)
{
	curs_set(0);
	ft_print_arr(s, 0, 0);
	refresh();
	if (flag == 0)
		usleep(3000000);
	else
		usleep(3000000);
	clear();
}
*/
