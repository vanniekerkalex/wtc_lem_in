/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 12:28:58 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/29 13:27:00 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		init_struct_2(t_lem_in *lem)
{
	int			i;

	lem->map = NULL;
	lem->rooms = 0;
	lem->link = 0;
	lem->start = 0;
	lem->end = 0;
	lem->len = 999;
	lem->rmf = (int *)malloc(sizeof(int) * 100);
	i = 0;
	while (i < 100)
		lem->rmf[i++] = -1;
	lem->lst = (char *)malloc(sizeof(char) * 2000);
	lem->lst = NULL;
	lem->viz = 0;
}

t_lem_in	*init_struct(void)
{
	t_lem_in	*lem;
	int			i;

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
	init_struct_2(lem);
	return (lem);
}

void		ft_print_links(t_lem_in *lem)
{
	char *s;
	int i;
	int j;

	i = 0;
	while (lem->data[i])
	{
		s = ft_strjoin(lem->data[i++], "\n");
		ft_putstr(s);
		j = 0;
		free(s);
	}
}

void		ft_convert_links(t_lem_in *lem)
{
	char	**str;
	int		i;
	int		j;
	int		k;

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
		j = 0;
		while (*(str + j))
			free(str[j++]);
		free(str);
	}
}

void		ft_check_match(t_lem_in *lem, char **str, int i, int j)
{
	if ((!ft_strcmp(lem->rm[i].name, str[0]) &&
	!ft_strcmp(lem->rm[j].name, str[1])) || (!ft_strcmp(lem->rm[i].name, str[1])
	&& !ft_strcmp(lem->rm[j].name, str[0])))
	{
		lem->map[i][j] = 1;
		lem->map[j][i] = 1;
	}
}
