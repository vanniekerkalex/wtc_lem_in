/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 17:33:20 by avan-ni           #+#    #+#             */
/*   Updated: 2018/06/02 18:44:32 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	size_t	len;
	char	temp;
	size_t	i;

	i = 0;
	len = ft_strlen(str) - 1;
	while (len > i)
	{
		temp = str[len];
		str[len--] = str[i];
		str[i++] = temp;
	}
	return (str);
}
