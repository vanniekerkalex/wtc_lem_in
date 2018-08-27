/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 21:18:42 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/27 12:19:21 by jde-agr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

int		move_rec(t_lem_in *lem, int ant, int rm, int count)
{
	if (lem->rm[lem->rmf[lem->len - 1]].size == lem->ants)
		return (1);
	if (rm <= 0)
	{
		write(1,"\n",1);
		//move_rec(lem, ant, lem->len - 1);
		move_rec(lem, 1, lem->len - 1, count);
		return (0);
	}
	else if (lem->rm[lem->rmf[rm]].size == 0 && lem->rm[lem->rmf[rm - 1]].size == 0)
	{
		//move_rec(lem, ant, rm - 1);
	}
	else if (lem->rm[lem->rmf[rm - 1]].size == 0 && lem->rm[lem->rmf[rm]].size >= 1)
	{
		return (0);
	}
	else if (rm == lem->len - 1 && lem->rm[lem->rmf[rm - 1]].size >= 1)
	{
		lem->rm[lem->rmf[rm - 1]].size--;
		lem->rm[lem->rmf[rm]].size++;
		print_ants(lem, ant + (count - ant), rm); //fix number for starting ant
		move_rec(lem, ant + (count - ant) + 1, rm - 1, count + 1); //introduced a count to identify when ant is done traversing the path
	}
	else if (lem->rm[lem->rmf[rm]].size == 0 && lem->rm[lem->rmf[rm - 1]].size >= 1)
	{
		lem->rm[lem->rmf[rm - 1]].size--;
		lem->rm[lem->rmf[rm]].size++;
		print_ants(lem, ant, rm);
		move_rec(lem, ant + 1, rm - 1, count);
	}
	move_rec(lem, ant, rm - 1, count);

	return (0);
}

/*void	sort_ite(t_lem_in *lem)
{
	int i;
	int j;
	int ant;

	ant = 1;
	while (lem->rm[lem->rmf[lem->len - 1]].size <= lem->ants)
	{
		i = 1;
		j = lem->len - 1;
		while (j >= 1)
		{
			if (j == lem->len - 1 && lem->rm[lem->rmf[j - 1]].size >= 1)
			{
				lem->rm[lem->rmf[j - 1]].size--;
				lem->rm[lem->rmf[j]].size++;
				print_ants(lem, i, j);
			}
			else if (lem->rm[lem->rmf[j - 1]].size >= 1 && lem->rm[lem->rmf[j]].size == 0)
			{
				lem->rm[lem->rmf[j - 1]].size--;
				lem->rm[lem->rmf[j]].size++;
				print_ants(lem, i, j);
			}
			j--;
		}
		i++;
		write(1, "\n", 1);
	}
}*/

void	print_ants(t_lem_in *lem, int ant, int rm)
{
	write(1,"L", 1);
	ft_putnbr(ant);
	write(1,"-", 1);
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
	//sort_ite(lem);
	move_rec(lem, 1, lem->len - 1, 1);
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
	//			printf("%s | %d\n", *(s + i), lem->rmf[i]);
			}
			j++;
		}
		i++;
	}
	printf("\n");
}
