/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 18:01:14 by mmanley           #+#    #+#             */
/*   Updated: 2018/05/16 18:50:57 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_addroom(t_room **alst, t_room *new)
{
	t_room *tmp;

	if (alst && new)
	{
		if (*alst)
		{
			tmp = *alst;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
		else if (new)
		{
		 	*alst = new;
		}
	}
}

t_room		*get_room(t_room *rooms, char *line, int *role)
{
	t_room	*new_room;
	char	**info;
	int		i;

	i = 0;
	if(!line || !(info = ft_strsplit(line, ' ')))
		return (NULL);
	if ((i = ft_tablen(info)) != 3)
		return (ft_room_error(NULL, info, line));
	if (!(new_room = ft_init_room(info, *role, 0, NULL)))
		return (ft_room_error(NULL, info, NULL));
	*role = 0;
	ft_addroom(&rooms, new_room);
	return (ft_room_error(rooms, info, NULL));
}

t_room		*the_room(t_room *rooms, char *line, int *ct, int fd)
{
	int		role;

	role = 0;
	if (*ct == 1 && !(ft_occ_pos(line, ' ') == -1 && line[0] != '#'))
	{
		ft_printf("ROOM ->LINES : %s\n", line);
		if (!(line = ft_check_rooms(line, &role, fd)))
			return (NULL);
		if (!(rooms = get_room(rooms, line, &role)))
			return (NULL);
	}
	return (rooms);
}
/*
int			ft_get_info(t_map **ants, t_room **rooms, int fd)
{
	char	*line;
	int		ct;
	int		role;

	line = NULL;
	ct = 0;
	role = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (!line || !line[0] || line[0] == 'L')
			return (ft_error(-1, NULL, "Bad file, TRY AGAIN if you Dare"));
		while (line && coments_everywhere(line) == 1)
		{
			ft_printf("++LINES : %s\n", line);
			if (get_next_line(fd, &line) < 1)
				return (-1);
		}
		if (ct == 0 && line[0] != '#')
		{
			ft_printf("++LINES : %s\n", line);
			if (!(*ants = get_ants(*ants, line)))
				return (-1);
			ct++;
		}
		else if (ct == 1 && !(ft_occ_pos(line, ' ') == -1 && line[0] != '#'))
		{
			ft_printf("++LINES : %s\n", line);
			if (!(line = ft_check_rooms(line, &role, fd)))
				return (-1);
			if (!(*rooms = get_room(*rooms, line, &role)))
				return (-1);
		}
		else
		{
			ct++;
			ft_printf("--LINES : %s\n", line);
			if (!(*rooms = get_links(*rooms, line)))
				return (-1);
		}
		ft_strdel(&line);
	}
	return (0);
}*/

int			ft_get_info(t_map **ants, t_room **rooms, int fd)
{
	char	*line;
	int		ct;
	int		role;

	line = NULL;
	ct = 0;
	role = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (!line || !line[0] || line[0] == 'L')
			return (ft_error(-1, NULL, "Bad file, TRY AGAIN if you Dare"));
		else if (!(line = comments(line, fd)))
			return (ft_error(-1, NULL, "PB with comments"));
		else if (ct == 0 && !(*ants = checking_ants(*ants, &line, &ct, fd)))
			return (ft_error(-1, NULL, "PB with ants"));
		else if (ct == 1 && !(*rooms = the_room(*rooms, line, &ct, fd)))
			return (ft_error(-1, NULL, line));
		else if (!(*rooms = our_link(*rooms, line, &ct)))
			return (ft_error(-1, NULL, "PB with links"));
	}
	return (0);
}
