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

int			ft_free_path(t_path **path, int nb)
{
	t_path	*tmp;
	t_path	*tmp2;

	tmp = *path;
	tmp2 = *path;
	if (tmp)
	{
		while (tmp->next)
		{
			// ft_printf("tmp [%p]\n", tmp);
			if (tmp->next->next)
				tmp2 = tmp2->next;
			tmp = tmp->next;
		}
		ft_printf("tmp [%d], %d, %p\n", tmp->yes, tmp->size, tmp->links);
		// ft_print_current_path(tmp);
		if (tmp->yes == 1)
			ft_printf("This is valid not going to free it :)\n");
		// ft_printf("path now [%p], path->next [%p]=(NULL)\n", tmp, tmp->next);
		if (tmp->yes == -1 || nb == 1)
		{
			// ft_printf("-path is non valid\n");
			tmp->size--;
			while (tmp->size > 0 && tmp->size--)
			{
				// ft_printf("-after setting the links to NULL\n");
				tmp->links[tmp->size] = NULL;
			}
			// ft_printf("Path size : %d\n", tmp->size);
			tmp->size = 0;
			free(tmp->links);
			tmp->links = NULL;
			// ft_printf("-freeing path->links [%p]\n", tmp->links);
			free(tmp);
			// ft_printf("-freeing path\n");
			tmp = NULL;
			tmp2->next = NULL;
			// ft_printf("-path freed [%p]\n", tmp);
			return (0);
		}
	}
	return (1);
}

int		main(void)
{
	t_map	*map;
	t_room	*rooms;
	t_room	*tmp;
	t_path	*path;
	t_path	*tmp2;
	t_path	*first_path;
	int		i = 0;

	map = NULL;
	rooms = NULL;
	first_path = NULL;
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
	while (1)
	{
		// ft_printf("SO...\n");
		if (!(path = ft_add_path(map, first_path)))
			return (-1);
		if (!first_path)
			first_path = path;
		/*if (ft_free_path(&first_path, path) == 0)
			path = NULL;*/
		// ft_printf("after free [%p]\n", path);
		// ft_printf("after free first_path [%p]\n", first_path);
		//ft_print_current_path(first_path);
		if (path && path->size == -1)
		{
			ft_printf("ALLORA SEI STRONZO!!\n\n\n");
			break;
		}
		if (path->yes == 1)
			i++;
		// ft_printf("before\n");
		ft_print_path(first_path, i);
		// ft_printf("after\n");
	}
	while (i--)
		ft_free_path(&first_path, 1);
	ft_printf("OVER\n");
	return (0);
}
