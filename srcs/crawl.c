/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crawl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:21:01 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/30 12:21:05 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		crawl_right(t_lem_in *lem, char *lst, int y, int x)
{
	if ((x > lem->rooms - 1 || y > lem->rooms - 1 || x < 0 || y < 0))
		return (0);
	if (lem->map[y][lem->rooms - 1] == 1)
	{
		lst = add_room(lem, lst, lem->rooms - 1);
		return (1);
	}
	if (lem->map[y][x] == 1)
	{
		lem->map[y][x] = 9;
		crawl_right(lem, lst, y, x + 1);
		lst = add_room(lem, lst, x);
		crawl_up(lem, lst, y - 1, x);
		crawl_down(lem, lst, y + 1, x);
	}
	else if (lem->map[y][x] == 9)
		return (0);
	else
		crawl_right(lem, lst, y, x + 1);
	return (0);
}

int		crawl_left(t_lem_in *lem, char *lst, int y, int x)
{
	if ((x > lem->rooms - 1 || y > lem->rooms - 1 || x < 0 || y < 0))
		return (0);
	if (lem->map[y][lem->rooms - 1] == 1)
	{
		lst = add_room(lem, lst, lem->rooms - 1);
		return (1);
	}
	if (lem->map[y][x] == 1)
	{
		lem->map[y][x] = 9;
		crawl_left(lem, lst, y, x - 1);
		lst = add_room(lem, lst, x);
		crawl_up(lem, lst, y - 1, x);
		crawl_down(lem, lst, y + 1, x);
	}
	else if (lem->map[y][x] == 9)
		return (0);
	else
		crawl_left(lem, lst, y, x - 1);
	return (0);
}

int		crawl_up(t_lem_in *lem, char *lst, int y, int x)
{
	if ((x > lem->rooms - 1 || y > lem->rooms - 1 || x < 0 || y < 0))
		return (0);
	if (lem->map[lem->rooms - 1][x] == 1)
	{
		lst = add_room(lem, lst, lem->rooms - 1);
		return (1);
	}
	if (lem->map[y][x] == 1)
	{
		lem->map[y][x] = 9;
		crawl_up(lem, lst, y - 1, x);
		lst = add_room(lem, lst, y);
		crawl_left(lem, lst, y, x - 1);
		crawl_right(lem, lst, y, x + 1);
	}
	else if (lem->map[y][x] == 9)
		return (0);
	else
		crawl_up(lem, lst, y - 1, x);
	return (0);
}

int		crawl_down(t_lem_in *lem, char *lst, int y, int x)
{
	if ((x > lem->rooms - 1 || y > lem->rooms - 1 || x < 0 || y < 0))
		return (0);
	if (lem->map[lem->rooms - 1][x] == 1)
	{
		lst = add_room(lem, lst, lem->rooms - 1);
		return (1);
	}
	if (lem->map[y][x] == 1)
	{
		lem->map[y][x] = 9;
		crawl_down(lem, lst, y + 1, x);
		lst = add_room(lem, lst, y);
		crawl_left(lem, lst, y, x - 1);
		crawl_right(lem, lst, y, x + 1);
	}
	else if (lem->map[y][x] == 9)
		return (0);
	else
		crawl_down(lem, lst, y + 1, x);
	return (0);
}

void	crawl(t_lem_in *lem)
{
	char *tmp;

	tmp = ft_strdup(lem->rm[0].name);
	crawl_right(lem, tmp, 0, 0);
	free(tmp);
}
