/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 17:37:37 by mmanley           #+#    #+#             */
/*   Updated: 2018/05/14 19:51:42 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"

typedef	struct		s_ants
{
	int				nb;
	struct s_ants	*next;
}					t_ants;
typedef struct		s_room
{
	char			*name;
	int				role;
	int				x;
	int				y;
	struct s_tube	*tube;
	struct s_room	*next;
}					t_room;
typedef struct		s_tube
{
	struct s_room	*tube;
	struct s_tube	*next;
}					t_tube;

int			ft_get_info(t_ants **ants, t_room **rooms, int fd);
t_tube		*ft_init_tubes(char *info, t_room *conct, t_room *curr);
void		ft_add_concts(t_tube **alst, t_tube *new);
t_room		*ft_init_room(char **info, int role, int i, t_room *new_room);

#endif
