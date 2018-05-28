/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 17:37:37 by mmanley           #+#    #+#             */
/*   Updated: 2018/05/23 15:35:03 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "printf/ft_printf.h"

typedef	struct		s_map
{
	int				ants;
	int				nb_rooms;
	struct s_room	*start;
}					t_map;
typedef struct		s_room
{
	char			*name;
	int				role;
	int				ant;
	int				x;
	int				y;
	int				open;
	int				link_chk;
	int				nb_l;
	struct s_room	**links;
	struct s_room	**bridge;
	struct s_room	*next;
}					t_room;
typedef struct		s_path
{
	struct s_room	**links;
	int				size;
	int				yes;
	struct s_path	*next;
}					t_path;

int					ft_free_path(t_path **path, int nb);
int					ft_get_info(t_map **ants, t_room **rooms, int fd);
t_room				*ft_init_room(char **info, int role, int i, t_room *nw_r);
void				ft_print_rooms(t_room *rooms, int details);
void				ft_print_links(t_room *rooms);
t_room				*get_links(t_room *rooms, char **info);
int					ft_check_validity(char *s);
char				*ft_check_rooms(char *line, int *role, int fd);
int					coments_everywhere(char *line);
int					ft_lstlen_test(t_room *lst);
t_room				*ft_room_error(t_room *ptr, char **info, char *s);
int					ft_error(int ret, char **info, char *s);
t_map				*checking_ants(t_map *ants, char **line, int *ct, int fd);
char				*comments(char *line, int fd);
t_room				*our_link(t_room *rooms, char *line, int *ct);
t_room				*the_room(t_room *rooms, char *line, int *ct, int fd);
t_map				*get_ants(t_map *ants, char *line);
char				*get_line_check(char *line, int fd);
int					lst_check(t_room *rooms);
t_path 				*ft_add_path(t_map *map, t_path *path);
void				ft_print_path(t_path *path, int nb);
void				ft_print_current_path(t_path *path);
t_path				*ft_init_path(t_path *new);

#endif
