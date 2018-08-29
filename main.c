/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:44:49 by avan-ni           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/08/28 12:39:32 by avan-ni          ###   ########.fr       */
=======
/*   Updated: 2018/08/29 11:00:56 by jde-agr          ###   ########.fr       */
>>>>>>> old-state
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
//	while (i < 2000)
//		free(lem->data[i++]);
	free(lem->data);
//	lem->data = NULL;
	i = 0;
//	while (i < lem->rooms)
//	{
//		free(lem->rm[i++].name);
//		lem->rm[i++].name = NULL;
//	}
	free(lem->rm);
<<<<<<< HEAD
//	lem->rm = NULL;
//	i = 0;
//	while (i < 100)
//	{
//		free(lem->links[i++]);
//		lem->links[i++] = NULL;
//	}
	free(lem->links);
//	lem->links = NULL;
//	i = 0;
//	while (i < lem->rooms)
//	{
//		free(lem->map[i++]);
//		lem->map[i++] = NULL;
//	}
=======
	i = 0;
	while (lem->links[i])
	{
		//ft_putstr("lo");
		//ft_strdel(&lem->links[i]);
		free(lem->links[i]);
		lem->links[i] = NULL;
		i++;
	}
	lem->links[0] = NULL;
	free(lem->links);
	i = 0;
	while (i < lem->rooms)
	{
		free(lem->map[i]);
		lem->map[i] = NULL;
		i++;
	}
>>>>>>> old-state
	free(lem->map);
	//lem->map = NULL;
	free(lem->lst);
<<<<<<< HEAD
//	lem->lst = NULL;
=======
	//lem->lst = NULL;
>>>>>>> old-state
	free(lem->rmf);
	//lem->rmf = NULL;
}

int		main(void)
{
	t_lem_in	*lem;

	lem = init_struct();
	ft_lem_in(lem);
<<<<<<< HEAD
	//ft_free(lem);
	//free(lem);
	//lem = NULL;
=======
	ft_free(lem);
	free(lem);
>>>>>>> old-state
	//while (1)
	//;
	return (0);
}
