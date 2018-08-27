/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:44:49 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/27 18:02:17 by jde-agr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_lem_in(t_lem_in *lem)
{
	ft_read(lem);
	ft_store(lem);
	if (is_error(lem))
		exit(0);
	ft_convert_links(lem);
	ft_print_links(lem);
	crawl(lem);
	if (!lem->lst)
	{
		ft_putstr("Error : No valid solution");
		exit(0);
	}
	sort_rooms(lem);
	move_ants(lem);
}

void ft_free(t_lem_in *lem)
{
	int i;

	i = 0;
	while (lem->data[i])
	{
		//ft_putstr("yo");
		free(lem->data[i]);
		lem->data[i] = NULL;
		i++;
	}
	lem->data[i] = NULL;
	free(lem->data);
	i = 0;
	while (lem->rm[i].name)
	{
		//ft_putstr("bo");
		free(lem->rm[i].name);
		lem->rm[i].name = NULL;
		i++;
	}
	lem->rm[i].name = NULL;
	free(lem->rm);
	/*i = 0;
	while (lem->links[i])
	{
		ft_putstr("lo");
		//ft_strdel(&lem->links[i]);
		free(lem->links[i]);
		i++;
	}
	lem->links[0] = NULL;
	free(lem->links);*/
	i = 0;
	while (i < lem->rooms)
	{
		free(lem->map[i]);
		lem->map[i] = NULL;
		i++;
	}
	free(lem->map);
	free(lem->lst);
	lem->lst = NULL;
	free(lem->rmf);
	lem->rmf = NULL;

	//free(lem);
}

int		main(void)
{
	t_lem_in	*lem;

	lem = init_struct();
	ft_lem_in(lem);
	ft_free(lem);
	//while (1)
	//;
	return (0);
}
