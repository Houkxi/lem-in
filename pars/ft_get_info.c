/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 18:01:14 by mmanley           #+#    #+#             */
/*   Updated: 2018/05/31 11:07:09 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_addroom(t_room **alst, t_room *new)
{
	t_room *tmp;

	if (alst && new)
	{
		if (*alst)
		{
			tmp = *alst;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
		else if (new)
			*alst = new;
	}
}

t_room		*get_room(t_room *rooms, char *line, int *role, t_map *map)
{
	t_room	*new_room;
	char	**info;
	int		i;

	i = 0;
	if (!line || !(info = ft_strsplit(line, ' ')))
		return (NULL);
	if ((i = ft_tablen(info)) != 3)
	{
		while ((map->nb_rooms -= 1) > 0)
			ft_free_rooms(&rooms);
		return (ft_room_error(NULL, info, line));
	}
	if (!(new_room = ft_init_room(info, *role, 0, NULL)))
	{
		while ((map->nb_rooms -= 1) > 0)
			ft_free_rooms(&rooms);
		return (ft_room_error(NULL, info, NULL));
	}
	*role = 0;
	ft_addroom(&rooms, new_room);
	map->nb_rooms += 1;
	return (ft_room_error(rooms, info, NULL));
}

int			ft_get_info(t_map **map, t_room **rooms, int fd)
{
	char	*line;
	int		ct;
	int		role;

	line = NULL;
	ct = 0;
	role = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (!line || !line[0] || line[0] == 'L')
			return (ft_error_str(-1, NULL, "Bad file, TRY AGAIN if you Dare"));
		while (line && coments_everywhere(line) == 1)
		{
			ft_printf("COMS : LINES : %s\n", line);
			if (!(line = get_line_check(line, fd)))
				return (ft_error_str(-1, NULL, "commentaire line if error"));
		}
		if (ct == 0 && line[0] != '#')
		{
			ft_printf("*%s\n", line);
			if (!(*map = get_ants(*map, line)))
				return (ft_error_str(-1, NULL, "ANTS not good"));
			ct++;
		}
		else if (ct == 1 && !(ft_occ_pos(line, ' ') == -1 && line[0] != '#'))
		{
			ft_printf("-%s\n", line);
			if (!(line = ft_check_rooms(line, &role, fd)))
				return (ft_error_str(-1, NULL, "Command not good"));
			if (!(*rooms = get_room(*rooms, line, &role, *map)))
				return (ft_error_str(-1, NULL, "Rooms not good"));
		}
		else
		{
			ct++;
			if (!(*rooms = our_link(*rooms, line, &ct)))
				return (ft_error_str(-1, NULL, "Links not good"));
		}
		ft_strdel(&line);
	}
	return (0);
}
