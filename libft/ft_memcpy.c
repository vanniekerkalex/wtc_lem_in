/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 17:47:43 by avan-ni           #+#    #+#             */
/*   Updated: 2018/05/28 17:59:06 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	if (!n || (!dst && !src))
		return (dst);
	s1 = (unsigned char*)dst;
	s2 = (unsigned char*)src;
	while (n--)
		*s1++ = *s2++;
	return (dst);
}
