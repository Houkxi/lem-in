/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <cfavero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:34:24 by cfavero           #+#    #+#             */
/*   Updated: 2018/05/29 20:18:20 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*ft_open_bridges(t_room *room)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!room)
		return (NULL);
	while (room->links[k])
		k++;
	while (room->bridge[i])
	{
		room->links[k++] = room->bridge[i];
		room->bridge[i++] = NULL;
	}
	room->nb_l = k;
	return (room);
}

t_path		*ft_close_path(t_path *path, t_path *new)
{
	int		i;
	int		k;

	i = 0;
	if (!path || !path->links || !new->links)
		return (NULL);
	while (path->links[i + 1] && new->links[i + 1] && \
		path->links[i + 1] == new->links[i + 1])
		i++;
	if (i < path->size)
	{
		k = 0;
		while (path->links[i]->bridge[k])
			k++;
		path->links[i]->bridge[k] = path->links[i + 1];
		path->links[i]->nb_l--;
		k = 0;
		while (path->links[i]->links[k] && path->links[i]->links[k] != path->links[i + 1])
			k++;
		while (path->links[i]->links[k + 1])
		{
			path->links[i]->links[k] = path->links[i]->links[k + 1];
			k++;
		}
		path->links[i]->links[k] = NULL;
	}
	return (path);
}

t_path		*ft_copy_path(t_room **links, t_path *new, int size, int len)
{
	t_room	*tmp;
	int		i;

	if (!new->links)
	{
		if (!(new->links = (t_room**)malloc(sizeof(t_room*) * len)))
			return (NULL);
		while (len--)
			new->links[len] = NULL;
	}
	i = 0;
	if (!links || !links[i])
		return (NULL);
	tmp = links[i];
	new->size = 0;
	while (size--)
	{
		if (tmp->nb_l == 1 && tmp->role != 1)
		{
			tmp = ft_open_bridges(tmp);
			break;
		}
		new->links[new->size] = tmp;
		new->size += 1;
		tmp = links[new->size];
	}
	return (new);
}

int     ft_check_around(t_path *path, t_room *room)
{
	int		i;
	int		size;
	t_room  *old_rooms;

	i = 0;
	size = path->size - 1;
	if (!path || !path->links || !path->links[i])
		return (1);
	old_rooms = path->links[i];
	while (old_rooms && size--)
	{
		if (old_rooms == room)
			return (-1);
		old_rooms = path->links[++i];
	}
	return (1);
}

t_path  *ft_find_path(t_path *path, t_room *room, int nb_rooms)
{
	t_room  *tmp;
	int     i;

	if (room->role == 1 && !path->links)
	{
		if (!path->links)
			if (!(path->links = (t_room**)malloc(sizeof(t_room*) * nb_rooms)))
				return (NULL);
		while (nb_rooms--)
			path->links[nb_rooms] = NULL;
		path->links[0] = room;
		path->size = 1;
	}
	if (room->role == -1 || (room->nb_l < 2 && room->role != 1))
	{
		if (room->role != -1)
		{
			room = ft_open_bridges(room);
			path->yes = -1;
		}
		return (path);
	}
	i = 0;
	while (room->links[i])
	{
		tmp = room->links[i];
		if (ft_check_around(path, tmp) == 1)
			break;
		i++;
		if (i == room->nb_l)
			break;
	}
	if (i == room->nb_l)
	{
		room = ft_open_bridges(room);
		path->yes = -1;
		if (room->role == 1)
		{
			path->size = -1;
			return (path);
		}
		return(path);

	}
	path->links[path->size] = tmp;
	path->size += 1;
	return (ft_find_path(path, tmp, nb_rooms));
}

t_path  *ft_add_path(t_map *map, t_path *path)
{
	t_path 	*new;
	t_path	*first;
	t_path	*save;
	int		len;

	if (!(new = ft_init_path(new)))
		return (NULL);
	if (path)
	{
		first = path;
		save = path;
		while (path->next)
		{
			if (path->next->next)
				save = save->next;
			path = path->next;
		}
		if (!(new = ft_copy_path(path->links, new, path->size - 1, map->nb_rooms)))
			return (NULL);
		if (!(path = ft_close_path(path, new)))
			return (NULL);
		 ft_printf("Path->yes = %d\n", path->yes);
		if (path && path->yes > 0)
		{
			if (map->path_size > 0 && map->path_size < path->size)
				path->yes = -1;
			else
				map->path_size = path->size;
		}
		// ft_printf("Path->size = %d, Min path_size = %d\n", path->size, map->path_size);
		if ((ft_free_path(&first, 0)) == 0)
			path = NULL;
		// ft_printf("After free\n");
		if (!(new = ft_find_path(new, new->links[new->size - 1], map->nb_rooms)))
			return (NULL);
		if (path)
		{
			path->next = new;
			path = path->next;
		}
		else
		{
			path = new;
			save->next = path;
		}
	}
	else
		if (!(path = ft_find_path(new, map->start, map->nb_rooms)))
			return (NULL);
	return (path);
}
