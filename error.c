/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-agr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 04:54:07 by jde-agr           #+#    #+#             */
/*   Updated: 2018/08/27 12:25:36 by jde-agr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	no_rooms(t_lem_in *lem)
{
	if (lem->rooms == 0)
	{
		ft_putstr("Error : No rooms");
		return (1);
	}
	return (0);
}

int	no_ants(t_lem_in *lem)
{
	if (lem->ants == 0)
	{
		ft_putstr("Error : No ants");
		return (1);
	}
	return (0);
}

int	no_man_comm(t_lem_in *lem)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (lem->data[i])
	{
		if (!ft_strcmp("##start", lem->data[i]) ||
				!ft_strcmp("##end", lem->data[i]))
			flag++;
		i++;
	}
	if (flag < 2)
	{
		ft_putstr("Error : No mandatory commands");
		return (1);
	}
	return (0);
}

int	is_error(t_lem_in *lem)
{
	if (no_ants(lem) || no_rooms(lem) || no_man_comm(lem))
		return (1);
	return (0);
}
