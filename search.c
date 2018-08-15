/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 10:55:55 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/15 14:55:20 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

void	ft_init_lists(t_lem_in *lem)
{
	int i;

	i = 0;
	lem->list = (char **)malloc(sizeof(char *) * lem->rooms);
	while (i < lem->rooms - 1)
		lem->list[i++] = ft_strnew(lem->rooms * 20); //for room name length
	lem->list[i] = NULL;
}

int		ft_is_in_list(char *node, char *list) // checks if already in the list
{
	int i;
	char **s;

	i = 0;
	//ft_putstr(list);
	//write(1, "\n", 1);
	s = ft_strsplit(list, '-');
	while (*(s + i))
	{
		if (!ft_strcmp(node, s[i++]))
			return(1);
	}
	return(0);
}

char	*ft_match_lists(t_lem_in *lem, char *node, char *list) // finds room and returns connected room
{
	int i;
	char **s;

	i = 0;
	while (i < lem->link)
	{
		s = ft_strsplit(lem->links[i], '-');
		if (!ft_strcmp(s[0], node) && !ft_is_in_list(s[1], list))
			return (s[1]);
		else if (!ft_strcmp(s[1], node) && !ft_is_in_list(s[0], list))
			return (s[0]);
		i++;
	}
	return (NULL);
}

char	*ft_create_lists(t_lem_in *lem, char *start, char *list) // recursively find lists and store
{
	char *str;

	if (!start)
		return (NULL);

	if (!ft_strlen(list))
		list = start;

	if (!ft_strcmp(lem->rm[lem->end].name, ft_match_lists(lem, start, list)))
	{
		write(1,"zzz\n",4);
		if (!ft_strcmp(list, ""))
			list = start;
		str = ft_strjoin(list, "-");
		list = ft_strjoin(str, lem->rm[lem->end].name);
		write(1,"zzz\n",4);
		return (list);
	}

	if(!ft_is_in_list(ft_match_lists(lem, start, list), list))
	{
		//if (!ft_strcmp(list, ""))
		//	list = ft_strdup(start);
		str = ft_strjoin(list, "-");
		list = ft_strjoin(str, ft_match_lists(lem, start, list));
		start = ft_match_lists(lem, start, list);
		ft_putstr(list);
		write(1, "\n", 1);
		write(1,"zzz\n",4);
		ft_create_lists(lem, start, list);
	}
	return (list);
}

void	ft_find_lists(t_lem_in *lem)
{
	char *str;

	ft_init_lists(lem);
	str = ft_create_lists(lem, lem->rm[lem->start].name, "");
	printf("\nList: %s\n", str);
}
