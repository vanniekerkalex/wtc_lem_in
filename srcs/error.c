/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-agr <jde-agr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 04:54:07 by jde-agr           #+#    #+#             */
/*   Updated: 2018/08/29 20:07:36 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	no_rooms(t_lem_in *lem)
{
	if (lem->rooms <= 0 || lem->rooms > 50)
	{
		ft_putstr("Error : Invalid rooms");
		return (1);
	}
	return (0);
}

int	no_ants(t_lem_in *lem)
{
	if (lem->ants <= 0 || lem->ants > 100)
	{
		ft_putstr("Error : Invalid ants");
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
