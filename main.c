/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:44:49 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/17 21:06:30 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

void	ft_lem_in(t_lem_in *lem)
{
	ft_read(lem);
	ft_store(lem);
	ft_convert_links(lem);
	ft_print_links(lem);
	crawl(lem);
	printf("Link: %s", lem->lst);
}

int main (void)
{
	t_lem_in	*lem;

	lem = init_struct();
	ft_lem_in(lem);
	return (0);
}
