/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 17:37:37 by mmanley           #+#    #+#             */
/*   Updated: 2018/05/16 18:19:05 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"

typedef	struct		s_map
{
	int				nb;
	int				nb_r;
	struct s_room	*strt;
}					t_map;
typedef struct		s_room
{
	char			*name;
	int				role;
	int				ant;
	int				x;
	int				y;
	int				nb_l;
	struct s_room	**links;
	struct s_room	*next;
}					t_room;

int					ft_get_info(t_map **ants, t_room **rooms, int fd);
t_room				*ft_init_room(char **info, int role, int i, t_room *new_room);
void				ft_print_rooms(t_room *rooms, int details);
void				ft_print_links(t_room *rooms);
t_room				*get_links(t_room *rooms, char *line);
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

#endif
