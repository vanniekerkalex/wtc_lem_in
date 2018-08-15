/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:44:49 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/14 16:52:16 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

//write(1,"yes\n", 4);

void	ft_lem_in(t_lem_in *lem)
{
	ft_read(lem);
	write(1,"yes\n", 4);
	ft_store(lem);
	write(1,"yes\n", 4);
	ft_convert_links(lem);
	write(1,"yes\n", 4);
	ft_print_links(lem);
}

int main (void)
{
	t_lem_in	*lem;

	lem = init_struct();
	ft_lem_in(lem);
	return (0);
}
