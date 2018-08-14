/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 17:28:34 by avan-ni           #+#    #+#             */
/*   Updated: 2018/05/28 17:47:14 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *ds;
	unsigned char *ss;

	if (!len)
		return (dst);
	else if (!src && !dst)
		return (NULL);
	ss = (unsigned char *)src;
	ds = (unsigned char *)dst;
	if (ss < ds)
	{
		ss = ss + len;
		ds = ds + len;
		while (len--)
			*--ds = *--ss;
	}
	else
		ft_memcpy(ds, ss, len);
	return (dst);
}
