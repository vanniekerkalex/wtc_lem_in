/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:44:49 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/15 18:00:10 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

//write(1,"yes\n", 4);

void	ft_lem_in(t_lem_in *lem)
{
	ft_read(lem);
	ft_store(lem);
	ft_convert_links(lem);
	ft_print_links(lem);
	//ft_find_lists(lem);
	shortest_list(lem, lem->rm[0].name, 0);
	lem->len = ft_count_list_len(lem);
	printf("\nLIST: %s LEN: %d\n", lem->lst, lem->len);
}

int main (void)
{
	t_lem_in	*lem;

	lem = init_struct();
	ft_lem_in(lem);
	return (0);
}
