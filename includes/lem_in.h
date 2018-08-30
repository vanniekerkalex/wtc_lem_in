/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:22:48 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/30 12:22:50 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <ncurses.h>

typedef struct	s_rm
{
	char	*name;
	int		x;
	int		y;
	int		size;
}				t_rm;

typedef struct	s_lem_in
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
	char	*lst;
	int		len;
	int		*rmf;
	int		viz;
}				t_lem_in;

t_lem_in		*init_struct(void);
void			ft_print_links(t_lem_in *lem);
void			ft_convert_links(t_lem_in *lem);
void			ft_check_match(t_lem_in *lem, char **str, int i, int j);

int				ft_read(t_lem_in *lem);
int				ft_store(t_lem_in *lem);
void			ft_swap_rooms(t_lem_in *lem);
void			ft_save_room(t_lem_in *lem, char *str);
void			ft_save_ants(t_lem_in *lem, char *str);

int				ft_is_in_list(char *node, char *list);
int				ft_count_list_len(t_lem_in *lem);
char			*add_room(t_lem_in *lem, char *lst, int rm);
int				crawl_count(char *lst);

void			crawl(t_lem_in *lem);
int				crawl_down (t_lem_in *lem, char *lst, int y, int x);
int				crawl_up (t_lem_in *lem, char *lst, int y, int x);
int				crawl_left (t_lem_in *lem, char *lst, int y, int x);
int				crawl_right (t_lem_in *lem, char *lst, int y, int x);

void			sort_rooms(t_lem_in *lem);
void			move_ants(t_lem_in *lem);
void			print_ants(t_lem_in *lem, int ant, int rm);
int				move_rec(t_lem_in *lem, int ant, int rm, int count);

int				is_error(t_lem_in *lem);
void			viz(t_lem_in *lem);

#endif
