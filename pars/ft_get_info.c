/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 18:01:14 by mmanley           #+#    #+#             */
/*   Updated: 2018/05/31 19:14:05 by mmanley          ###   ########.fr       */
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

t_room		*get_room(t_room **rooms, char *line, int *role, t_map *map)
{
	t_room	*new_room;
	char	**info;
	int		i;

	i = 0;
	if (!line || !(info = ft_strsplit(line, ' ')))
		return (NULL);
	if ((i = ft_tablen(info)) != 3)
		ft_exit(&(*rooms), &map, NULL);
	if (!(new_room = ft_init_room(info, *role, 0, NULL)))
		ft_exit(&(*rooms), &map, NULL);
	*role = 0;
	ft_addroom(&(*rooms), new_room);
	map->nb_rooms += 1;
	return (ft_room_error(*rooms, info, NULL));
}

int			ft_get_info(t_map **map, t_room **rooms, int fd)
{
	char	*line;
	int		ct;
	int		role;
	int		ret;

	line = NULL;
	ct = 0;
	role = 0;
	ret = -1;
	while (get_next_line(fd, &line) > 0)
	{
		if ((ret = ft_basic_checks(line, &role, ret)) == -1)
			return (ft_error_str(-1, line, NULL));
		if (ret == 1)
		{
			if (!(*map = get_ants(*map, line, role)))
				return (ft_error_str(-1, line, NULL));
			ct++;
		}
		else if (ret == 2 && ct == 1)
		{
			if (!(get_room(&(*rooms), line, &role, *map)))
				return (ft_error_str(-1, line, NULL));
		}
		else if (ret == 3)
		{
			if (!(our_link(&(*rooms), line, &ct, role)))
				return (ft_error_str(-1, line, NULL));
		}
		if (ret != 0 && ct < 1 && role != 0)
			return (ft_error_str(-1, line, NULL));
		ft_printf("%s\n", line);
		ft_strdel(&line);
	}
	if (ret != 3)
		return (ft_error_str(-1, NULL, NULL));
	return (0);
}
