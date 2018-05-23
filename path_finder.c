/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <cfavero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:34:24 by cfavero           #+#    #+#             */
/*   Updated: 2018/05/23 11:36:32 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_check_openess(t_room *room, int nb_l, t_room *past)
{
	int		i;

	i = 0;
	ft_printf("ft_check_openess\n");
	if (!room || !room->links[0])
		return (-1);
	while (i < nb_l)
	{
		if (!(room->links[i]->open == -1 || room->links[i] == past))
			return (1);
		i++;
	}
	return (0);
}

t_path		*ft_close_path(t_path *path, t_path *new)
{
	int		i;

	i = 0;
	while (path->next)
		path = path->next;
	while (path->links[i] == new->links[i])
		i++;
	if (i < path->size)
		if (path->links[i]->role != -1)
			path->links[i]->open = -1;
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
	while (size--)
	{
		if (tmp->open == -1 || tmp->links[0]->role == -1 /*|| tmp->nb_l == 0*/)
		{
			tmp->open = -1;
			/*while (tmp->links[i])
				tmp->links[i++]->open = 1;*/
			break;
		}
		// tmp->nb_l--;
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
	ft_printf("find check, room -> [%s] -->%d \n", room->name, room->open);
	if (room->open != 1 || room->role == 1)
		return (-1);
	while (old_rooms && size--)
	{
		// if (old_rooms && old_rooms->name)
			// ft_printf("Old rooms --> %s\n", old_rooms->name);
		if (old_rooms == room)
			return (ft_error(-1, NULL, "already been here"));
		old_rooms = path->links[i++];
	}
	return (ft_error(1, NULL, "CHECK AROUND GOOD"));
}

t_path  *ft_find_path(t_path *path, t_room *room, t_room *past)
{
	t_room  *tmp;
	int     i;

	//ft_printf("find path Yolo  %d\n", room->nb_l);
	if (room->role == -1 || (room->nb_l < 2 && room->role != 1))
	{
		if (room->role != -1)
		{
			path->yes = -1;
			//room->open = -1;
		}
		return (path);
	}
	i = 0;
	if (room->links[0]->role == 1)
		i++;
	/*if (ft_check_openess(room, room->nb_l, past) == 0)
	{
		ft_printf("ALL CLOSED\n");
		room->open = -1;
		return (path);
	}*/
	while (room->links[i]->open == -1 || room->links[i] == past)
	{
		i++;
		if (room->links[i - 1]->open == -1)
		{
			room->links[i - 1]->open = 1;
			room->link_chk += 1;
			ft_printf("Opening -> %s, %d ------- My room %s  link_chk = %d / %d = nb_l\n", room->links[i -1]->name, room->links[i -1]->open, room->name, room->link_chk, room->nb_l);
			if (room->link_chk == room->nb_l)
			{
				ft_printf("ALL CLOSED\n");
				room->open = -1;
				return (path);
			}
		}
	}
	 ft_printf("MY CURR is %s  --> %d\n", room->links[i]->name, room->links[i]->open);
	while (room->links[i])
	{
		//ft_printf("find path Yolo while \n");
		tmp = room->links[i];
		ft_printf("curr = %s\n", tmp->name);
		//ft_printf("find Yolo whileeee \n");
		if (ft_check_around(path, tmp) == 1)
		{
			ft_printf("BREAKING\n");
			break;
		}
		//ft_printf("room open wasn't 1 \n");
		i++;
	}
	if (!room->links[i])
	{
		ft_printf("Id end %d\n", i);
		path->yes = -1;
		return(path);
	}
	//ft_printf("find check X45 %s \n", tmp->name);
	if (!path->links)
		if (!(path->links = (t_room**)malloc(sizeof(t_room*) * 15)))
			return (NULL);
	path->links[path->size] = tmp;
	ft_printf("path->links[path->size] --> %s\n", path->links[path->size]->name);
	//path->links[path->size]->open = -1;
	path->size += 1;
	//ft_printf("find check X4896 \n");
	return (ft_find_path(path, tmp, path->links[path->size - 2]));
}

t_path  *ft_add_path(t_map *map, t_path *path)
{
	t_path 	*new;
	int		len;

	if (!(new = (t_path*)malloc(sizeof(t_path))))
		return (NULL);
	len = map->nb_rooms;
	new->links = NULL;
	new->size = 0;
	new->yes = 1;
	new->next = NULL;
	//ft_printf("starting room : [%s]\n", map->start->name);
	if (path)
	{
		//ft_printf("Before copy, %d, %d\n", path->size, map->nb_rooms);
		while (path->next)
			path = path->next;
		new = ft_copy_path(path->links, new, path->size - 1, map->nb_rooms);
		path = ft_close_path(path, new);
		// ft_printf("--------------PATH SENT------------\n");
		// ft_print_path(path, 1);
		// ft_printf("------------------------------\n");
		ft_printf("Last sent -->%s\n", new->links[new->size - 1]->name);
		new = ft_find_path(new, new->links[new->size - 1], new->links[new->size - 2]);
		//ft_printf("Yolo 2 \n");
		path->next = new;
	}
	else
	{
		//ft_printf("Yolo 3 \n");
		path = ft_find_path(new, map->start, NULL);
		//ft_printf("Yolo 4 \n");
	}
	return (path);
}
