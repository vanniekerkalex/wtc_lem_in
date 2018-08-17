/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 21:18:42 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/17 22:55:41 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

int		move_rec(t_lem_in *lem, int ant)
{
	if (lem->rm[lem->rmf[lem->len - 1]].size == lem->ants)
		return (1);
	if (ant != 0 && lem->rm[lem->rmf[ant]].size == 0)
	{
		lem->rm[lem->rmf[ant]].size++;
		lem->rm[lem->rmf[ant - 1]].size--;
		print_ants(lem, ant);
	}
	if (lem->rm[lem->rmf[ant]].size > 0)
	{
		move_rec(lem, ant + 1);
	}
	return (0);
}

void	print_ants(t_lem_in *lem, int ant)
{
	write(1,"L", 1);
	ft_putnbr(ant);
	write(1,"-", 1);
	ft_putstr(lem->rm[lem->rmf[ant]].name);
}

void	move_ants(t_lem_in *lem)
{
	lem->rm[lem->rmf[0]].size = lem->ants;
	move_rec(lem, 0);
}

void	sort_rooms(t_lem_in *lem)
{
	int i;
	int j;
	char **s;

	i = 0;
	s = ft_strsplit(lem->lst, '-');
	while (*(s + i))
	{
		j = 0;
		while (j <= lem->rooms - 1)
		{
			if (!ft_strcmp(*(s + i),lem->rm[j].name))
			{
				lem->rmf[i] = j;
				printf("%s | %d\n", *(s + i), lem->rmf[i]);
			}
			j++;
		}
		i++;
	}
	printf("\n");
}
