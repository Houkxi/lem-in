/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_links.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 13:22:13 by mmanley           #+#    #+#             */
/*   Updated: 2018/05/30 11:25:54 by mmanley          ###   ########.fr       */
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
	int		len = 15;
	t_room	*tmp;

	i = room->nb_l;
	if (!links)
	{
		if (!(links = (t_room**)malloc(sizeof(t_room*) * len)))
			return (NULL);
		while (--len)
			links[len] = NULL;
	}
	tmp = l;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, info) == 0 && tmp != room)
		{
			if (check_links(links, tmp, i) == -1)
				break ;
			links[room->nb_l] = tmp;
			room->nb_l += 1;
		}
		tmp = tmp->next;
	}
	room->links = links;
	return (room);
}

t_room		*get_links(t_room *rooms, char **info)
{
	t_room	*tmp;
	int		i;

	tmp = rooms;
	i = 0;
	if (check_link_name(rooms, info[i]) == -1)
	{
		ft_printf("Problem test\n\n");
		return (ft_room_error(NULL, info, "Wrong link name, LEARN HOW!!!"));
	}
	if (check_link_name(rooms, info[i + 1]) == -1)
	{
		ft_printf("Problem test\n\n");
		return (ft_room_error(NULL, info, "Wrong link name, LEARN HOW!!!"));
	}
	while (tmp)
	{
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
	char	**info;
	int		i;

	i = 0;
	if (*ct != -10)
	{
		if (lst_check(rooms) == -1)
			return (ft_room_error(NULL, NULL, "NEED a start & an end"));
		*ct = -10;
	}
	if (!line || !rooms || !(info = ft_strsplit(line, '-')))
		return (NULL);
	if ((i = ft_tablen(info)) != 2)
		return (ft_room_error(NULL, info, "PB in our link names"));
		ft_printf("+LINES : %s\n", line);
		if (!(rooms = get_links(rooms, info)))
			return (NULL);
		return (rooms);
}
