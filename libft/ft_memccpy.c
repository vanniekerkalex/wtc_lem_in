/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 17:57:50 by avan-ni           #+#    #+#             */
/*   Updated: 2018/05/28 18:09:48 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *ds;
	unsigned char *ss;

	ds = (unsigned char *)dst;
	ss = (unsigned char *)src;
	while (n)
	{
		if ((*ds++ = *ss++) == (unsigned char)c)
			return ((void *)ds);
		n--;
	}
	return (NULL);
}
