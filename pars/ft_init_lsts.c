/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_lsts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 19:22:28 by mmanley           #+#    #+#             */
/*   Updated: 2018/05/23 19:01:37 by mmanley          ###   ########.fr       */
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
	int len = 15;

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
	new_room->link_chk = 0;
	new_room->next = NULL;
	new_room->links = NULL;
	if (!(new_room->bridge = (t_room**)malloc(sizeof(t_room*) * len)))
		return (NULL);
	while (len--)
		new_room->bridge[len] = NULL;
	new_room->nb_l = 0;
	return (new_room);
}

t_path			*ft_init_path(t_path *new)
{
	if (!(new = (t_path*)malloc(sizeof(t_path))))
		return (NULL);
	new->links = NULL;
	new->size = 0;
	new->yes = 1;
	new->next = NULL;
	return (new);
}
