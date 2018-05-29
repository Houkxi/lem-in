/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 16:17:40 by mmanley           #+#    #+#             */
/*   Updated: 2018/05/29 14:46:14 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_free_map(t_map **map)
{
	if (*map)
	{
		ft_printf("Freeing map\n");
		(*map)->ants = 0;
		(*map)->nb_rooms = 0;
		(*map)->path_size = 0;
		(*map)->start = NULL;
		free(*map);
		*map = NULL;
	}
}

void		ft_free_rooms(t_room **rooms)
{
	t_room	*tmp;
	int		i;

	i = 0;
	tmp = *rooms;
	if (tmp)
	{
		ft_printf("Freeing room\n");
		ft_strdel(&tmp->name);
		tmp->nb_l--;
		while (tmp->links && tmp->links[tmp->nb_l] && tmp->nb_l < 0 && tmp->nb_l--)
			tmp->links[tmp->nb_l] = NULL;
		tmp->nb_l = 0;
		free(tmp->links);
		while (tmp->bridge && tmp->bridge[i])
			tmp->bridge[i++] = NULL;
		free(tmp->bridge);
		if (tmp->next)
			*rooms = tmp->next;
		free(tmp);
	}
}

int			ft_free_path(t_path **path, int nb)
{
	t_path	*tmp;
	t_path	*tmp2;

	tmp = *path;
	tmp2 = *path;
	if (tmp)
	{
		ft_printf("Freeing path nb [%d]\n", nb);
		while (tmp->next)
		{
			if (tmp->next->next)
				tmp2 = tmp2->next;
			tmp = tmp->next;
		}
		if (tmp->yes == -1 || nb > 0)
		{
			tmp->size--;
			while (tmp->size > 0 && tmp->size--)
				tmp->links[tmp->size] = NULL;
			tmp->size = 0;
			free(tmp->links);
			tmp->links = NULL;
			free(tmp);
			if (tmp != tmp2)
				tmp2->next = NULL;
			tmp = NULL;
			return (0);
		}
	}
	return (1);
}

t_path		*ft_get_path(t_path *first_path, t_map *map, int *i)
{
	t_path	*path;

	while (1)
	{
		if (!(path = ft_add_path(map, first_path)))
		{
			if (first_path)
				while ((*i -= 1) > 0)
					ft_free_path(&first_path, 2);
			return (NULL);
		}
		if (!first_path)
			first_path = path;
		(first_path == path) ? map->path_size = first_path->size : map->path_size;
		if (path && path->size == -1)
		{
			path->size = 2;
			break;
		}
		(path->yes == 1) ? *i += 1 : *i;
		ft_print_path(first_path, *i);
	}
	return (first_path);
}

int			main(void)
{
	t_map	*map;
	t_room	*rooms;
	t_room	*tmp;
	t_path	*first_path;
	int		i;

	map = NULL;
	rooms = NULL;
	first_path = NULL;
	i = 0;
	if (ft_get_info(&map, &rooms, 0) == -1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	tmp = rooms;
	map->nb_rooms = ft_lstlen_test((t_room*)rooms) + 1;
	while (tmp)
	{
		if (tmp->role == 1)
			break ;
		tmp = tmp->next;
	}
	tmp->open = -1;
	map->start = tmp;
	ft_printf("ANT nb = %d, NB of R = %d, start Name : %s\n", map->ants,\
	map->nb_rooms, map->start->name);
	if (!(first_path = ft_get_path(first_path, map, &i)))
		return (-1);
	if (i > 0)
		i += 1;
	while (i--)
		ft_free_path(&first_path, 3);
	while (map->nb_rooms--)
		ft_free_rooms(&rooms);
	ft_free_map(&map);
	ft_printf("OVER\n");
	return (0);
}
