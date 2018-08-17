/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 12:28:58 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/17 21:03:57 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_lem_in	*init_struct(void)
{
	t_lem_in	*lem;
	int i;

	lem = (t_lem_in *)malloc(sizeof(t_lem_in));
	lem->data = (char **)malloc(sizeof(char *) * 2000);
	lem->ants = 0;
	lem->rm = (t_rm *)malloc(sizeof(t_rm) * 1000);
	i = 0;
	while (i < 1000)
	{
		lem->rm[i].name = NULL;
		lem->rm[i].x = 0;
		lem->rm[i].y = 0;
		lem->rm[i++].size = 0;
	}
	lem->links = (char **)malloc(sizeof(char *) * 100);
	i = 0;
	while (i < 1000 - 1)
		lem->links[i++] = ft_strnew(50);
	lem->links[i] = NULL;
	lem->map = NULL;
	lem->rooms = 0;
	lem->link = 0;
	lem->start = 0;
	lem->end = 0;
	lem->len = 999;
	return (lem);
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

	printf("Rooms: %d\n", lem->rooms);

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
