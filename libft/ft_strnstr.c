/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:42:47 by avan-ni           #+#    #+#             */
/*   Updated: 2018/06/04 12:44:27 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	size_t	length;
	size_t	count;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	length = ft_strlen((char *)needle);
	if (length == 0 || *needle == '\0')
		return ((char *)hay);
	while (*(hay + i) && (i + length) <= len && *hay != '\0')
	{
		k = 0;
		count = 0;
		if (*(hay + i) == *needle)
		{
			j = i;
			while (*(hay + j) == *(needle + k++) && *(hay + j) && ++count)
				j++;
			if (count == length || length == 1)
				return ((char *)(hay + i));
		}
		i++;
	}
	return (NULL);
}
