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
	while (path->next)
		path = path->next;
	while (path->links[i + 1] == new->links[i + 1])
		i++;
	if (i < path->size)
	{
			k = 0;
			while (path->links[i]->bridge[k])
				k++;
			path->links[i]->bridge[k] = path->links[i + 1];
			ft_printf("Closing link [%s] from room [%s]\n", path->links[i + 1]->name, path->links[i]->name);
			path->links[i]->nb_l--;
			k = 0;
			while (path->links[i]->links[k] != path->links[i + 1])
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
		if (!(new->links = (t_room**)malloc(sizeof(t_room*) * len)))
			return (NULL);
	i = 0;
	tmp = links[i];
	ft_printf("COPY PATH\n tmp = [%s]; size = %d\n", tmp->name, size);
	while (size--)
	{
		if (tmp->nb_l == 1 && tmp->role != 1)
		{
			ft_printf("tmp [%s] doesn't have links anymore, time to bridge back\n", tmp->name);
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
	size = path->size;
	if (!path || !path->links || !path->links[i])
		return (1);
	old_rooms = path->links[i];
	/*if (/*room->open != 1 || room->role == 1)
	{
		ft_printf("- current room is the first\n");
		return (-1);
	}*/
	while (old_rooms /*&& size--*/)
	{
		if (old_rooms == room)
		{
			ft_printf("- we have already been in this room\n");
			return (-1);
		}
		old_rooms = path->links[i++];
	}
	return (1);
}

t_path  *ft_find_path(t_path *path, t_room *room)
{
	t_room  *tmp;
	int     i;

	if (room->role == 1 && !path->links)
	{
		ft_printf("are we here again?\n");
		ft_printf("links[%d]\n", path->size);
		if (!path->links)
			if (!(path->links = (t_room**)malloc(sizeof(t_room*) * 15)))
				return (NULL);
		path->links[0] = room;
		ft_printf("links[%d] : [%s]\n", path->size, path->links[0]->name);
		path->size = 1;
		// ft_printf("links[%d] : [%s]\n", path->size, path->links[path->size]->name);
		return (ft_find_path(path, room));
	}
	if (room->role == -1 || (room->nb_l < 2 && room->role != 1))
	{
		if (room->role != -1)
		{
			ft_printf("The room [%s] doesn't have links anymore\n", room->name);
			room = ft_open_bridges(room);
			ft_printf("--------Opening room [%s]\n", room->name);
			path->yes = -1;
		}
		ft_printf("are we here?\n");
		return (path);
	}
	i = 0;
	while (room->links[i])
	{
		tmp = room->links[i];
		ft_printf("Current room we are checking : [%s]\n", tmp->name);
		if (ft_check_around(path, tmp) == 1)
			break;
		ft_printf("- we go to next link\n");
		i++;
		// ft_printf("now ? %s\n", room->links[i]->name);
		if (i == room->nb_l)
			break;
	}
	if (i == room->nb_l)
	{
		ft_printf("We checked all the links of [%s] --> FAIL\n", room->name);
		room = ft_open_bridges(room);
		ft_printf("--------Opening room [%s]\n", room->name);
		path->yes = -1;
		return(path);
	}
	if (!path->links)
		if (!(path->links = (t_room**)malloc(sizeof(t_room*) * 15)))
			return (NULL);
	ft_printf("Room [%s] has been added to the path\n", tmp->name);
	path->links[path->size] = tmp;
	path->size += 1;
	ft_print_path(path, -1);
	return (ft_find_path(path, tmp));
}

t_path  *ft_add_path(t_map *map, t_path *path)
{
	t_path 	*new;
	int		len;

	if (!(new = ft_init_path(new)))
		return (NULL);
	if (path)
	{
		while (path->next)
			path = path->next;
			ft_printf("Size : %d\n", path->size);
		new = ft_copy_path(path->links, new, path->size - 1, map->nb_rooms);
		path = ft_close_path(path, new);
		new = ft_find_path(new, new->links[new->size - 1]);
		path->next = new;
	}
	else
		path = ft_find_path(new, map->start);
	return (path);
}
