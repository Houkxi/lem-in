/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 18:01:14 by mmanley           #+#    #+#             */
/*   Updated: 2018/06/01 19:09:11 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_check_rooms(char *line, int role)
{
	if (!line)
		return (-2);
	if (ft_strcmp("##start", line) == 0)
		return (1);
	else if (ft_strcmp("##end", line) == 0)
		return (-1);
	return (role);
}

void		ft_addroom(t_room **alst, t_room *new)
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

int			check_room_name(char *name, t_room *rooms)
{
	t_room	*tmp;

	tmp = rooms;
	if (!tmp)
		return (0);
	while (tmp)
	{
		if (ft_strcmp(name, tmp->name) == 0)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
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
	if (check_room_name(info[0], *rooms) == -1)
		ft_exit(&(*rooms), &map, NULL);
	if (!(new_room = ft_init_room(info, *role, 0, NULL)))
		ft_exit(&(*rooms), &map, NULL);
	*role = 0;
	ft_addroom(&(*rooms), new_room);
	map->nb_rooms += 1;
	return (ft_room_error(*rooms, info, NULL));
}

int			ft_get_info(t_map **map, t_room **rooms, int role, int ct)
{
	char	*line;
	int		ret;

	line = NULL;
	ret = -1;
	while (get_next_line(0, &line) > 0)
	{
		if ((ret = ft_basic_checks(line, &role, ret)) == -1)
			return (ft_error_str(-1, line, NULL));
		if (ret == 1)
			if (!(*map = get_ants(*map, line, role, &ct)))
				return (ft_error_str(-1, line, NULL));
		if (ret == 2 && ct == 1)
			if (!(get_room(&(*rooms), line, &role, *map)))
				return (ft_error_str(-1, line, NULL));
		if (ret == 3)
			if (!(our_link(&(*rooms), line, &ct, role)))
				return (ft_error_str(-1, line, NULL));
		if ((ret != 1 && ct < 1 && role != 0) || role_ch(role, *rooms) == -1)
			return (ft_error_str(-1, line, NULL));
		ft_error_str(0, line, line);
	}
	if (ret != 3 && ct != -10)
		return (ft_error_str(-1, NULL, NULL));
	return (0);
}
