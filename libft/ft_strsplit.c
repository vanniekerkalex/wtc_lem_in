/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 14:33:30 by avan-ni           #+#    #+#             */
/*   Updated: 2018/06/05 15:39:59 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (!(str = (char **)malloc(sizeof(char *) * (ft_wcount(s, c) + 1))))
		return (NULL);
	while (i < ft_wcount(s, c))
	{
		k = 0;
		if (!(str[i] = ft_strnew((ft_lcount(&s[j], c)))))
			return (NULL);
		while (*(s + j) == c)
			j++;
		while (*(s + j) != c && *(s + j))
			*(str[i] + k++) = *(s + j++);
		i++;
	}
	*(str + i) = NULL;
	return (str);
}
