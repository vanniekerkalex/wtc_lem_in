/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_delaft.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 14:22:22 by avan-ni           #+#    #+#             */
/*   Updated: 2018/06/20 14:18:48 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew_delaft(char *s, char c)
{
	size_t i;

	i = 0;
	while (*(s + i) != c && *(s + i))
		i++;
	if (i == ft_strlen(s))
		return (s);
	else
		return (ft_strdup((const char *)(s + i + 1)));
}
