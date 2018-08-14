/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-agr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 14:14:03 by jde-agr           #+#    #+#             */
/*   Updated: 2018/08/04 14:14:14 by jde-agr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			sign;
	long int	sum;

	sign = 1;
	sum = 0;
	while (ft_isspace((char)(*str)))
		str++;
	if ((char)*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if ((char)*str == '+')
		str++;
	while (ft_isdigit((char)*str))
	{
		if ((sign > 0 && ((sum * 10) + (*str - '0')) > 2147483647)
		|| (sign < 0 && ((sum * 10) + (*str - '0')) > 2147483648))
			return (0);
		sum = (sum * 10) + (*str - '0');
		str++;
	}
	if (*str && !ft_isdigit((char)*str))
		return (0);
	return (sum * sign);
}
