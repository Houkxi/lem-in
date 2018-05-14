/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 16:17:40 by mmanley           #+#    #+#             */
/*   Updated: 2018/05/14 20:58:57 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_print_rooms(t_room *rooms)
{
	int i;
	int y;
	t_tube	*tube;

	i = 0;
	y = 0;
	while (rooms->next)
	{
		tube = rooms->tube;
		ft_printf("*********ROOM n_%02d*********\n", i++);
		ft_printf("Room name --> %s\n", rooms->name);
		ft_printf("It's role --> %d\n", rooms->role);
		ft_printf("It's coord --> (%d, %d)\n", rooms->x, rooms->y);
		ft_printf("Connection ");
		/*while (tube && tube->next)
		{
			ft_printf("1 %p\n", tube->tube->name);
			ft_printf("-->%02d-[%s]", y++, tube->tube->name);
			ft_printf("2 %p\n", tube->next);
			tube = tube->next;
			ft_printf("3 %p\n", tube);
		}*/
		ft_printf("*****************************\n");
		rooms = rooms->next;
	}
	tube = rooms->tube;
	ft_printf("*********ROOM n_%02d*********\n", i++);
	ft_printf("Room name --> %s\n", rooms->name);
	ft_printf("It's role --> %d\n", rooms->role);
	ft_printf("It's coord --> (%d, %d)\n", rooms->x, rooms->y);
	/*while (tube->next)
	{
		ft_printf("Connection -->%02d-[%s]", y++, tube->tube->name);
		ft_printf("TESTING 1\n");
		tube = tube->next;
		ft_printf("TESTING 2\n");
	}
	ft_printf("Connection -->%02d-[%s]\n", y++, tube->tube->name);*/
	ft_printf("*****************************\n");
}

int		main()
{
	t_ants	*ants;
	t_room	*rooms;

	ants = NULL;
	rooms = NULL;
	ft_get_info(&ants, &rooms, 0);
	ft_printf("ANT nb = %d\n", ants->nb);
	ft_print_rooms(rooms);
	ft_printf("ENDING\n");
	return (0);
}
