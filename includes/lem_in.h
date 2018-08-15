/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:59:36 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/15 17:58:21 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <ncurses.h>

typedef struct	rm
{
	char	*name;
	int		x;
	int		y;
	int		size;
}				t_rm;

typedef struct	pos
{
	int		x;
	int		y;
}				t_pos;

typedef struct	lem_in
{
	char	**data;
	int		ants;
	t_rm	*rm;
	char	**links;
	int		**map;
	int		rooms;
	int		link;
	int		start;
	int		end;
	char	**list;
	char	*lst;
	t_pos	*pos;
	int		len;

}				t_lem_in;

t_lem_in	*init_struct(void);
int			ft_store(t_lem_in *lem);
int			ft_read(t_lem_in *lem);
void		ft_swap_rooms(t_lem_in *lem);

void		ft_save_room(t_lem_in *lem, char *str);
void		ft_save_ants(t_lem_in *lem, char *str);
void		ft_convert_links(t_lem_in *lem);
void 		ft_check_match(t_lem_in *lem, char **str, int i, int j);

void		ft_print_links(t_lem_in *lem);

void		ft_find_lists(t_lem_in *lem);

int		shortest_list(t_lem_in *lem, char *lst, int dir);
int 	ft_count_list_len(t_lem_in *lem);

#endif
