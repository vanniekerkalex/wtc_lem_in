/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lcount.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 13:31:50 by avan-ni           #+#    #+#             */
/*   Updated: 2018/06/02 16:07:45 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lcount(char const *str, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (!str)
		return (0);
	while (*(str + i) == c)
		i++;
	while (*(str + i) != c && *(str + i))
	{
		i++;
		len++;
	}
	return (len);
}
