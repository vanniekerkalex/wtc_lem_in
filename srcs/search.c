/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-agr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 10:49:31 by jde-agr           #+#    #+#             */
/*   Updated: 2018/08/30 11:16:10 by jde-agr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_is_in_list(char *node, char *list)
{
	int		i;
	int		j;
	char	**s;

	i = 0;
	s = ft_strsplit(list, '-');
	while (*(s + i))
	{
		if (!ft_strcmp(node, s[i]))
		{
			j = 0;
			while (*(s + i + j))
				free(s[i + j++]);
			free(s);
			return (1);
		}
		free(s[i++]);
	}
	free(s);
	return (0);
}

int		ft_count_list_len(t_lem_in *lem)
{
	char	**str;
	int		len;

	str = ft_strsplit(lem->lst, '-');
	len = 0;
	while (*(str + len))
		free(str[len++]);
	free(str);
	return (len);
}

char	*add_room(t_lem_in *lem, char *lst, int rm)
{
	char *s;

	if (!ft_is_in_list(lem->rm[rm].name, lst))
	{
		s = ft_strjoin(lst, "-");
		lst = ft_strjoin(s, lem->rm[rm].name);
		free(s);
		if (rm == lem->rooms - 1)
		{
			if (crawl_count(lst) < lem->len)
			{
				lem->len = crawl_count(lst);
				free(lem->lst);
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
	{
		free(str[len]);
		len++;
	}
	free(str);
	return (len);
}
