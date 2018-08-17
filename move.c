/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 21:18:42 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/17 21:43:09 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*void	move_ants(t_lem_in *lem)
{
	lem->rm[lem->rmf[0]] = lem->ants;
	while (lem->ants >= 0)
}*/

void	sort_rooms(t_lem_in *lem)
{
	int i;
	int j;
	char **s;

	i = 0;
	s = ft_strsplit(lem->lst, '-');
	while (*(s + i))
	{
		j = 0;
		while (j <= lem->rooms - 1)
		{
			if (!ft_strcmp(*(s + i),lem->rm[j++].name))
				lem->rmf[i] = j;
		}
		i++;
	}
}
