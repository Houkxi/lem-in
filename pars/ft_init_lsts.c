/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_lsts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 19:22:28 by mmanley           #+#    #+#             */
/*   Updated: 2018/05/16 15:22:29 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room			*coord_check(t_room *room, char **info, int i)
{
	if (ft_check_validity(info[1]) == -1 || ft_check_validity(info[2]) == -1)
		return (ft_room_error(NULL, NULL, "Error in coordonates"));
	if (i == 1)
		room->x = ft_atoi(info[i]);
	if (i == 2)
		room->y = ft_atoi(info[i]);
	return (room);
}

t_room			*ft_init_room(char **info, int role, int i, t_room *new_room)
{
	if (!(new_room = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	while (info[i])
	{
		if (i > 2)
		{
			free(new_room);
			return (NULL);
		}
		if (i == 0)
			new_room->name = ft_strdup(info[i]);
		if (!(new_room = coord_check(new_room, info, i)))
			return (NULL);
		i++;
	}
	new_room->role = role;
	new_room->ant = 0;
	new_room->open = 1;
	new_room->next = NULL;
	new_room->links = NULL;
	new_room->nb_l = 0;
	return (new_room);
}
