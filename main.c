/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 16:17:40 by mmanley           #+#    #+#             */
/*   Updated: 2018/05/31 18:56:26 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_fill_map(t_map **map, t_room *rooms)
{
	t_room	*tmp;
	int		len;

	tmp = rooms;
	(*map)->nb_rooms = ft_lstlen_test((t_room*)rooms) + 1;
	while (tmp)
	{
		if (tmp->role == 1)
			break ;
		tmp = tmp->next;
	}
	if (!tmp)
		return (-1);
	tmp->open = -1;
	(*map)->start = tmp;
	(*map)->start->len = 1;
	if (!((*map)->links = (t_room**)malloc(sizeof(t_room*) * (*map)->nb_rooms)))
		return (-1);
	len = (*map)->nb_rooms;
	while (len--)
		(*map)->links[len] = NULL;
	(*map)->links[0] = (*map)->start;
	return (0);
}

t_path		*ft_get_path(t_path *first_path, t_map *map, int *i, t_room *rooms)
{
	t_path	*path;
	t_path	*new;

	if ((map->path_size = ft_find_shortest_path(map->links, 0, 1)) == -1)
	{
		ft_exit(&rooms, &map, &first_path);
		return (NULL);
	}
	while (1)
	{
		if (!(new = ft_init_path(new)))
			ft_exit(&rooms, &map, &first_path);
		if (!first_path)
			if (!(path = ft_find(new, map->start, map->nb_rooms, map)))
				return (NULL);
		if (!first_path)
			first_path = path;
		else if (!(path = ft_add_path(map, first_path, &first_path, new)))
			ft_exit(&rooms, &map, &first_path);
		if (path && path->size == -1)
		{
			path->size = 2;
			break ;
		}
		(path->yes == 1 && path->size <= map->path_size) ? *i += 1 : *i;
	}
	return (first_path);
}

int			ft_run_forest_run(t_path *first_path, t_map *map, t_room *rooms)
{
	int i;

	i = 0;
	if (!(first_path = ft_get_path(first_path, map, &i, rooms)))
		return (-1);
	ft_print_path(first_path, 214748634, 0);

	(i > 0) ? i += 1 : i;
	while (i--)
		ft_free_path(&first_path, 1, first_path, first_path);
	while (map->nb_rooms--)
		ft_free_rooms(&rooms);
	ft_free_map(&map);
	return (0);
}

int			main(void)
{
	t_map	*map;
	t_room	*rooms;
	t_path	*first_path;

	map = NULL;
	rooms = NULL;
	first_path = NULL;
	if (ft_get_info(&map, &rooms, 0) == -1)
	{
		ft_exit(&rooms, &map, NULL);
		return (0);
	}
	if (ft_fill_map(&map, rooms) == -1)
		return (-1);
	if (ft_run_forest_run(first_path, map, rooms) == -1)
		return (-1);
	return (0);
}
