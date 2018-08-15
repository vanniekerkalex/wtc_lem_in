/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:47:29 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/15 21:18:27 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

int	ft_read(t_lem_in *lem)
{
	char *line;
	int i;

	i = 0;
	while (get_next_line(0, &line))
	{
		if (!ft_strcmp(line, ""))
		{
			free(line);
			return (0);
		}
		else
			lem->data[i++] = ft_strdup(line);
		free(line);
	}
	lem->data[i] = NULL;
	free(line);
	return (1);
}

int		ft_store(t_lem_in *lem)
{
	int i;

	i = 0;
	while (lem->data[i])
	{
		if (!ft_strcmp(lem->data[i], "##start"))
			lem->start = lem->rooms;
		else if (!ft_strcmp(lem->data[i], "##end"))
			lem->end = lem->rooms;
		else if (ft_strchr(lem->data[i], ' '))
			ft_save_room(lem, lem->data[i]);
		else if (ft_strchr(lem->data[i], '-'))
			lem->links[lem->link++] = ft_strdup(lem->data[i]);
		else
			ft_save_ants(lem, lem->data[i]);
		i++;
	}
	lem->links[lem->link] = NULL;
	lem->rm[lem->rooms].name = NULL;
	ft_swap_rooms(lem);
	return (1);
}

void	ft_swap_rooms(t_lem_in *lem)
{
	t_rm temp;
	if (lem->start != 0)
	{
		temp.name = lem->rm[0].name;
		temp.x = lem->rm[0].x;
		temp.y = lem->rm[0].y;
		lem->rm[0].name = lem->rm[lem->start].name;
		lem->rm[0].x = lem->rm[lem->start].x;
		lem->rm[0].y = lem->rm[lem->start].y;
		lem->rm[lem->start].name = temp.name;
		lem->rm[lem->start].x = temp.x;
		lem->rm[lem->start].y = temp.y;
	}
	if (lem->end != lem->rooms - 1)
	{
		temp.name = lem->rm[lem->rooms - 1].name;
		temp.x = lem->rm[lem->rooms - 1].x;
		temp.y = lem->rm[lem->rooms - 1].y;
		lem->rm[lem->rooms - 1].name = lem->rm[lem->end].name;
		lem->rm[lem->rooms - 1].x = lem->rm[lem->end].x;
		lem->rm[lem->rooms - 1].y = lem->rm[lem->end].y;
		lem->rm[lem->end].name = temp.name;
		lem->rm[lem->end].x = temp.x;
		lem->rm[lem->end].y = temp.y;
	}
}

void ft_save_room(t_lem_in *lem, char *str)
{
	char **s;

	s = ft_strsplit(str, ' ');
	lem->rm[lem->rooms].name = ft_strdup(s[0]);
	lem->rm[lem->rooms].x = ft_atoi(s[1]);
	lem->rm[lem->rooms++].y = ft_atoi(s[2]);
}

void ft_save_ants(t_lem_in *lem, char *str)
{
	if (((lem->ants = ft_atoi(str)) == 0) && (ft_strcmp(str, "0")
		|| ft_strcmp(str, "-0"))) //not actually equal to 0
		//error
		write(1, "ants #\n", 7);
	//else
		//ok
}

void ft_start_end(t_rm rm, char *str)
{
	char **s;

	s = ft_strsplit(str, ' ');
	rm.name = ft_strdup(s[0]);
	rm.x = ft_atoi(s[1]);
	rm.y = ft_atoi(s[2]);
}

void	ft_print_links(t_lem_in *lem)
{
	int i;
	int j;

	i = 0;
	while (lem->data[i])
		printf("Data: %s\n", lem->data[i++]);

	i = 0;
	while (lem->links[i])
		printf("Links: %s\n", lem->links[i++]);

	i = 0;
	while (lem->rm[i].name)
	{
		printf("Name: %s X: %d Y: %d\n", lem->rm[i].name,lem->rm[i].x,lem->rm[i].y);
		i++;
	}

	i = 0;
	while (i < lem->rooms)
	{
		j = 0;
		if (i == 0)
		{
			printf("  ");
			while (j < lem->rooms)
				printf("%s ", lem->rm[j++].name);
			printf("\n");
		}
		printf("%s ", lem->rm[i].name);
		j = 0;
		while (j < lem->rooms)
			printf("%d ", lem->map[i][j++]);
		printf("\n");
		i++;
	}

	printf("Start: %d | %s End: %d | %s", lem->start, lem->rm[lem->start].name, lem->end, lem->rm[lem->end].name);
}

void	ft_convert_links(t_lem_in *lem)
{
	char **str;
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	lem->map = (int **)malloc(sizeof(int *) * lem->rooms);
	while (i < lem->rooms)
		lem->map[i++] = (int *)malloc(sizeof(int) * lem->rooms);
	while (k < lem->link)
	{
		str = ft_strsplit(lem->links[k++], '-');
		i = -1;
		while (++i < lem->rooms)
		{
			j = -1;
			while (++j < lem->rooms)
				ft_check_match(lem, str, i, j);
		}
	}
}

void ft_check_match(t_lem_in *lem, char **str, int i, int j)
{
	if ((!ft_strcmp(lem->rm[i].name, str[0]) &&
	!ft_strcmp(lem->rm[j].name, str[1])) || (!ft_strcmp(lem->rm[i].name, str[1])
	&& !ft_strcmp(lem->rm[j].name, str[0])))
	{
		lem->map[i][j] = 1;
		lem->map[j][i] = 1;
	}
}
