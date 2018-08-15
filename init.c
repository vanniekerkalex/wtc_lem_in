/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 12:28:58 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/15 17:55:45 by avan-ni          ###   ########.fr       */
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
	lem->pos = (t_pos *)malloc(sizeof(t_pos));
	lem->pos[0].x = 0;
	lem->pos[0].y = 0;
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
	lem->len = 0;
	return (lem);
}
