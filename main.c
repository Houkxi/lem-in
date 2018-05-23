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
	ft_print_rooms(rooms, 1);
	while (i < 50)
	{
		path = ft_add_path(map, path);
		ft_printf("********************PATH %02d*********************\n", i++);
		ft_print_path(path, i);
		ft_printf("**************************************************\n\n\n");
	}
	//ft_printf("open = %d\n", path->links[1]->open);
	return (0);
}
