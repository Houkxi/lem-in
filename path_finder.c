/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <cfavero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:34:24 by cfavero           #+#    #+#             */
/*   Updated: 2018/05/31 18:06:27 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path		*ft_starting_room(t_path *path, t_map *map, t_room *room, int i)
{
	i = map->path_size;
	if (!path->links)
		if (!(path->links = (t_room**)malloc(sizeof(t_room*) * i)))
			return (NULL);
	while (i--)
		path->links[i] = NULL;
	path->links[0] = room;
	path->size = 1;
	return (path);
}

t_room		*ft_find_room(t_room *room, t_path *path, t_room *tmp, int *i)
{
	*i = room->nb_l;
	while ((*i -= 1) > 0)
	{
		if (room->links[*i]->role == -1)
		{
			tmp = room->links[*i];
			break ;
		}
	}
	if (!tmp)
	{
		*i = 0;
		while (room->links[*i])
		{
			tmp = room->links[*i];
			if (ft_check_around(path, tmp) == 1)
				break ;
			*i += 1;
			if (*i == room->nb_l)
				break ;
		}
	}
	return (tmp);
}

t_path		*ft_find(t_path *path, t_room *room, int nb_rooms, t_map *map)
{
	t_room	*tmp;
	int		i;

	if (room->role == 1 && !path->links)
		if (!(path = ft_starting_room(path, map, room, 0)))
			return (NULL);
	if (room->role == -1 || (room->nb_l < 2 && room->role != 1) \
		|| (map->path_size <= path->size))
	{
		(room->role != -1) ? room = ft_open_bridges(room) : 0;
		(room->role != -1) ? path->yes = -1 : 0;
		return (path);
	}
	i = 0;
	tmp = ft_find_room(room, path, NULL, &i);
	if (i == room->nb_l)
	{
		room = ft_open_bridges(room);
		path->yes = -1;
		(room->role == 1) ? path->size = -1 : 0;
		return (path);
	}
	path->links[path->size] = tmp;
	path->size += 1;
	return (ft_find(path, tmp, nb_rooms, map));
}

t_path		*ft_do_stuff(t_path *path, t_path **save, t_path *new, int i)
{
	if (i == 0)
	{
		while (path->next)
		{
			if (path->next->next)
				*save = (*save)->next;
			path = path->next;
		}
	}
	return (path);
}

t_path		*ft_add_path(t_map *map, t_path *path, t_path **first, t_path *nw)
{
	t_path	*save;
	int		k;

	save = path;
	path = ft_do_stuff(path, &save, nw, 0);
	k = (*first == path) ? 1 : 0;
	if (!(nw = ft_copy(path->links, nw, path->size - 1, map->path_size)))
		return (NULL);
	if (!(path = ft_close_path(path, nw, 0, 0)))
		return (NULL);
	if ((ft_free_path(&(*first), 0, *first, *first)) == 0)
		path = NULL;
	if (!(nw = ft_find(nw, nw->links[nw->size - 1], map->nb_rooms, map)))
		return (NULL);
	(path) ? path->next = nw : 0;
	(path) ? path = path->next : 0;
	if (!path)
	{
		path = nw;
		(k == 0) ? save->next = path : 0;
		(k != 0) ? *first = nw : 0;
		(k != 0) ? save = NULL : 0;
	}
	return (path);
}
