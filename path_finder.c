/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <cfavero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:34:24 by cfavero           #+#    #+#             */
/*   Updated: 2018/05/23 19:04:18 by mmanley          ###   ########.fr       */
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
	// ft_printf("path [%p]\n", path);
	if (!path || !path->links || !new->links)
		return (NULL);
	// while (path->next)
	// 	path = path->next;
	// ft_printf("path [%p]\n", path);
	// ft_printf("path links i [%p], path links i + 1 [%p]\n new links i [%p], new links i + 1 [%p]\n", path, path->links[i + 1], new->links[i], new->links[i + 1]);

	while (path->links[i + 1] && new->links[i + 1] && \
		path->links[i + 1] == new->links[i + 1])
		i++;
	// ft_printf("buuuuu 2 \n");
	if (i < path->size)
	{
		// ft_printf("buuuuu 3\n");
		k = 0;
		while (path->links[i]->bridge[k])
			k++;
			// ft_printf("buuuuu 4\n");
		path->links[i]->bridge[k] = path->links[i + 1];
		// ft_printf("buuuuu 4.3\n");
		path->links[i]->nb_l--;
		// ft_printf("buuuuu 4.4\n");
		k = 0;
		while (path->links[i]->links[k] && path->links[i]->links[k] != path->links[i + 1])
			k++;
		// ft_printf("buuuuu 4.5\n");
		while (path->links[i]->links[k + 1])
		{
			path->links[i]->links[k] = path->links[i]->links[k + 1];
			k++;
		}
		// ft_printf("buuuuu 5\n");
		path->links[i]->links[k] = NULL;
	}
	return (path);
}

t_path		*ft_copy_path(t_room **links, t_path *new, int size, int len)
{
	t_room	*tmp;
	int		i;

	ft_printf("cpy path\n");
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
			ft_printf("Opening bridges\n");
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
		{
			return (-1);
		}
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
		// ft_printf("\n------------------------------------++++++++++\n");
		// ft_print_current_path(new);
		// ft_printf("----------------------------------------+++++++\n");
		if (!(new = ft_copy_path(path->links, new, path->size - 1, map->nb_rooms)))
			return (NULL);
		if (!(path = ft_close_path(path, new)))
			return (NULL);
		if ((ft_free_path(&first, 0)) == 0)
			path = NULL;
		if (!(new = ft_find_path(new, new->links[new->size - 1], map->nb_rooms)))
			return (NULL);
		// ft_printf("\n+++++++++++++++++++++++++++++++++\n");
		// ft_print_current_path(new);
		// ft_printf("+++++++++++++++++++++++++++++++++\n");
		if (path)
		{
			path->next = new;
			path = path->next;
		}
		else
		{
			ft_printf("Bad path modified %p\n", path);
			path = new;
			save->next = path;
		}
	}
	else
		if (!(path = ft_find_path(new, map->start, map->nb_rooms)))
			return (NULL);
	return (path);
}
