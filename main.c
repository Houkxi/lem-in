/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 16:17:40 by mmanley           #+#    #+#             */
/*   Updated: 2018/05/16 14:37:30 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main()
{
	t_map	*ants;
	t_room	*rooms;
	t_room	*tmp;

	ants = NULL;
	rooms = NULL;
	if (ft_get_info(&ants, &rooms, 0) == -1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	tmp = rooms;
	ants->nb_r = ft_lstlen_test((t_room*)rooms);
	while (tmp)
	{
		if (tmp->role == 1)
			break;
		tmp = tmp->next;
	}
	ants->strt = tmp;
	ft_printf("ANT nb = %d, NB of R = %d, start Name : %s\n", ants->nb, ants->nb_r, ants->strt->name);
	ft_print_rooms(rooms, 1);
	ft_printf("ENDING\n");
	return (0);
}
