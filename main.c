/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:44:49 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/27 12:21:06 by jde-agr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>
#include <stdlib.h>
void	ft_lem_in(t_lem_in *lem)
{
	ft_read(lem);
	ft_store(lem);
	if (is_error(lem))
		exit (0);
	ft_convert_links(lem);
	ft_print_links(lem);
	crawl(lem);
//	printf("Link: %s\n", lem->lst);
//	printf("Ants: %d\n", lem->ants);
	if (!lem->lst)
	{
		ft_putstr("Error : No valid solution");
		exit(0);
	}
	sort_rooms(lem);
	move_ants(lem);
}

int main (void)
{
	t_lem_in	*lem;

	lem = init_struct();
	ft_lem_in(lem);
	return (0);
}
