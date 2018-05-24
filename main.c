/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 16:17:40 by mmanley           #+#    #+#             */
/*   Updated: 2018/05/23 19:04:50 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_free_path(t_path *path_or)
{
	t_path	*path;

	path = path_or;
	if (path)
	{
		ft_printf("I'm going to free shit or libero lo stronzo\n");
		while (path->next && path->yes != -1)
		{
			ft_printf("[%p], [%p], [%p]\n", path, path->next, path->next->next);
			path = path->next;
		}
		if (path->yes == -1)
		{
			ft_printf("-path is non valid\n");
			path->size--;
			while (path->size--)
			{
				ft_printf("-after setting the links to NULL\n");
				path->links[path->size] = NULL;
			}
			path->size = 0;
			free(path->links);
			path->links = NULL;
			ft_printf("-freeing path->links\n");
			free(path);
			ft_printf("-freeing path\n");
			path->next = NULL;
			path = NULL;
		}
	}
}

int		main(void)
{
	t_map	*map;
	t_room	*rooms;
	t_room	*tmp;
	t_path	*path;
	int		i = 0;

	map = NULL;
	rooms = NULL;
	path = NULL;
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
	// ft_print_rooms(rooms, 1);
	// path = ft_add_path(map, path);
	// while (path->size != -1)
		// path = ft_add_path(map, path);
	while (i < 83)
	{
		path = ft_add_path(map, path);
		// ft_free_path(path);
		if (path->size == -1)
		{
			ft_printf("ALLORA SEI STRONZO!!\n\n\n");
			ft_printf("LIBERO LO STRONZO!!\n\n\n");
			break;
		}
		// ft_printf("********************PATH %02d*********************\n", i++);
		// ft_printf("Size outside: %d\n", path->size);
		i++;
		ft_print_path(path, i);
		// ft_printf("%d\n", i);
		// ft_printf("**************************************************\n\n\n");
	}
	ft_printf("!!!!!!!!!!!!!!!!!!!!!\nI WAS to tired to find the problem || to stupid T.T\nBut I think our list of paths isn't really a list\nWe always give back the last as the first one\n");
	// ft_order_path(path);
	//ft_printf("open = %d\n", path->links[1]->open);
	return (0);
}
