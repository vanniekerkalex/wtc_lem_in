/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 10:55:55 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/27 13:16:39 by jde-agr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_is_in_list(char *node, char *list)
{
	int		i;
	char	**s;

	i = 0;
	s = ft_strsplit(list, '-');
	while (*(s + i))
	{
		if (!ft_strcmp(node, s[i++]))
			return (1);
	}
	return (0);
}

int		ft_count_list_len(t_lem_in *lem)
{
	char	**str;
	int		len;

	str = ft_strsplit(lem->lst, '-');
	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

char	*add_room(t_lem_in *lem, char *lst, int rm)
{
	if (!ft_is_in_list(lem->rm[rm].name, lst))
	{
		lst = ft_strjoin(lst, "-");
		lst = ft_strjoin(lst, lem->rm[rm].name);
		if (rm == lem->rooms - 1)
		{
			if (crawl_count(lst) < lem->len)
			{
				lem->len = crawl_count(lst);
				lem->lst = ft_strdup(lst);
			}
		}
	}
	return (lst);
}

int		crawl_count(char *lst)
{
	char	**str;
	int		len;

	str = ft_strsplit(lst, '-');
	len = 0;
	while (*(str + len))
		len++;
	return (len);
}
