/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:59:36 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/18 12:40:24 by avan-ni          ###   ########.fr       */
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
	char	*lst;
	int		len; // number of rooms in final list
	int		*rmf; //order of rooms in list
}				t_lem_in;

// INIT.C
t_lem_in	*init_struct(void);
void		ft_print_links(t_lem_in *lem);
void		ft_convert_links(t_lem_in *lem);
void 		ft_check_match(t_lem_in *lem, char **str, int i, int j);

//READ.C
int			ft_read(t_lem_in *lem);
int			ft_store(t_lem_in *lem);
void		ft_swap_rooms(t_lem_in *lem);
void		ft_save_room(t_lem_in *lem, char *str);
void		ft_save_ants(t_lem_in *lem, char *str);

//SEARCH.C
int		ft_is_in_list(char *node, char *list);
int 	ft_count_list_len(t_lem_in *lem);
char	*add_room(t_lem_in *lem, char *lst, int rm);
int		crawl_count(char *lst);

// CRAWL.C
void	crawl(t_lem_in *lem);
int 	crawl_down (t_lem_in *lem, char *lst, int y, int x);
int 	crawl_up (t_lem_in *lem, char *lst, int y, int x);
int 	crawl_left (t_lem_in *lem, char *lst, int y, int x);
int 	crawl_right (t_lem_in *lem, char *lst, int y, int x);

// MOVE.C
void	sort_rooms(t_lem_in *lem);
void	move_ants(t_lem_in *lem);
void	print_ants(t_lem_in *lem, int ant, int rm);
int		move_rec(t_lem_in *lem, int ant, int rm);

#endif
