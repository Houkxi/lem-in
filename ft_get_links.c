/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_links.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 13:22:13 by mmanley           #+#    #+#             */
/*   Updated: 2018/05/16 18:50:10 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			check_links(t_room **links, t_room *tmp, int size)
{
	while (size)
		if (links[size--] == tmp)
			return (-1);
	return (0);
}

int			check_link_name(t_room *rooms, char *link)
{
	t_room	*tmp;

	tmp = rooms;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, link) == 0)
			return (0);
		tmp = tmp->next;
	}
	ft_print_rooms(rooms, -9);
	return (-1);
}

t_room		*ft_init_links(char *info, t_room **links, t_room *room, t_room *l)
{
	int		i;
	t_room	*tmp;

	i = room->nb_l;

	if (!links)
		if (!(links = (t_room**)malloc(sizeof(t_room*) * 10))) /// Rewrite it later on
			return (NULL);
	tmp = l;
	//ft_printf("room_nb_l = %d\n", room->nb_l);
	while (tmp)
	{
		if (ft_strcmp(tmp->name, info) == 0 && tmp != room)
		{
			if (check_links(links, tmp, i) == -1)
				break ;
			links[room->nb_l] = tmp;
			room->nb_l += 1;
			//ft_printf("WHAT IS YOUR NAME -- %s <---> %s, link nbs = %d, Link name --> %s\n", tmp->name, room->name, room->nb_l, links[i]->name);
		}
		tmp = tmp->next;
	}
	room->links = links;
	return (room);
}

t_room		*get_links(t_room *rooms, char *line)
{
	char	**info;
	t_room	*tmp;
	int		i;

	if (!line || !rooms || !(info = ft_strsplit(line, '-')))
		return (NULL);
	if ((i = ft_tablen(info)) != 2)
		return (ft_room_error(rooms, info, NULL));
	tmp = rooms;
	i = 0;
	while (tmp)
	{
		if (check_link_name(rooms, info[i]) == -1)
			return (ft_room_error(NULL, info, "Wrong link name, LEARN HOW TO WRITE!!!"));
		if (ft_strcmp(tmp->name, info[i]) == 0 && i < 2)
		{
			if (!(tmp = ft_init_links(info[1 - i], tmp->links, tmp, rooms)))
				return (ft_room_error(NULL, info, "Problem in links"));
			if (i == 0)
				tmp = rooms;
			if (i == 0)
				i++;
		}
		tmp = tmp->next;
	}
	return (ft_room_error(rooms, info, NULL));
}

t_room		*our_link(t_room *rooms, char *line, int *ct)
{
	*ct += 1;
	ft_printf("--LINES : %s\n", line);
	if (!(rooms = get_links(rooms, line)))
		return (NULL);
	return (rooms);
}
