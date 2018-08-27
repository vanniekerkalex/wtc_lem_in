/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 21:18:42 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/27 16:40:43 by jde-agr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	move_rec_2(t_lem_in *lem, int ant, int rm, int count)
{
	lem->rm[lem->rmf[rm - 1]].size--;
	lem->rm[lem->rmf[rm]].size++;
	if (rm == lem->len - 1)
	{
		print_ants(lem, ant + (count - ant), rm);
		move_rec(lem, ant + (count - ant) + 1, rm - 1, count + 1);
	}
	else
	{
		print_ants(lem, ant, rm);
		move_rec(lem, ant + 1, rm - 1, count);
	}
}

int		move_rec(t_lem_in *lem, int ant, int rm, int count)
{
	if (lem->rm[lem->rmf[lem->len - 1]].size == lem->ants)
		return (1);
	if (rm <= 0)
	{
		write(1, "\n", 1);
		move_rec(lem, 1, lem->len - 1, count);
		return (0);
	}
	else if (lem->rm[lem->rmf[rm - 1]].size == 0
		&& lem->rm[lem->rmf[rm]].size >= 1)
		return (0);
	else if (lem->rm[lem->rmf[rm - 1]].size >= 1)
	{
		move_rec_2(lem, ant, rm, count);
	}
	move_rec(lem, ant, rm - 1, count);
	return (0);
}

void	print_ants(t_lem_in *lem, int ant, int rm)
{
	write(1, "L", 1);
	ft_putnbr(ant);
	write(1, "-", 1);
	ft_putstr(lem->rm[lem->rmf[rm]].name);
	if (ft_strcmp(lem->rm[lem->rmf[rm]].name, lem->rm[lem->end].name)
		&& (ant != lem->ants))
		write(1, " ", 1);
	if (!ft_strcmp(lem->rm[lem->rmf[rm]].name, lem->rm[lem->end].name)
		&& (ant != lem->ants))
		write(1, " ", 1);
}

void	move_ants(t_lem_in *lem)
{
	lem->rm[lem->rmf[0]].size = lem->ants;
	move_rec(lem, 1, lem->len - 1, 1);
	write(1, "\n", 1);
}

void	sort_rooms(t_lem_in *lem)
{
	int		i;
	int		j;
	char	**s;

	i = 0;
	s = ft_strsplit(lem->lst, '-');
	while (*(s + i))
	{
		j = 0;
		while (j <= lem->rooms - 1)
		{
			if (!ft_strcmp(*(s + i), lem->rm[j].name))
				lem->rmf[i] = j;
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}
