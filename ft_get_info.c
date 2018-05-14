/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 18:01:14 by mmanley           #+#    #+#             */
/*   Updated: 2018/05/14 21:00:01 by mmanley          ###   ########.fr       */
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

t_ants		*get_ants(t_ants *ants, char *line)
{
	int ant_nb;

	if (!line || (ant_nb = ft_atoi(line)) == 0)
		return (NULL);
	if (!(ants = (t_ants*)malloc(sizeof(t_ants))))
		return (NULL);
	ants->nb = ant_nb;
	return (ants);
}

int			ft_tablen(char **tab)
{
	int		y;

	y = 0;
	if (!tab || !*tab)
		return (-1);
	while (tab[y])
		y++;
	return (y);
}

t_room		*get_room(t_room *rooms, char *line, int *role)
{
	t_room	*new_room;
	char	**info;
	int		i;

	i = 0;
	if (!line)
		return (NULL);
	if(!(info = ft_strsplit(line, ' ')))
		return (NULL);
	if ((i = ft_tablen(info)) != 3)
	{
		ft_printf("TEST = %s, %d\n", line, i);
		ft_deltab(info);
		return (rooms);
	}
	if (!(new_room = ft_init_room(info, *role, 0, NULL)))
		return (NULL);
	*role = 0;
	ft_addroom(&rooms, new_room);
	ft_deltab(info);
	return (rooms);
}

t_room		*get_connections(t_room *rooms, char *line)
{
	char	**info;
	t_room	*tmp;
	t_tube	*new;
	int		i;

	if (!line || !rooms)
		return (NULL);
	if (!(info = ft_strsplit(line, '-')))
		return (NULL);
	tmp = rooms;
	i = 0;
	while (tmp->next)
	{
		if (ft_strcmp(tmp->name, info[0]) == 0)
		{
			if (!(new = ft_init_tubes(info[1], rooms, tmp)))
				return (NULL);
			ft_add_concts(&tmp->tube, new);
		}
		if (ft_strcmp(tmp->name, info[1]) == 0)
		{
			if (!(new = ft_init_tubes(info[0], rooms, tmp)))
				return (NULL);
			ft_add_concts(&tmp->tube, new);
		}
		tmp = tmp->next;
	}
	ft_deltab(info);
	return (rooms);
}

int			ft_get_info(t_ants **ants, t_room **rooms, int fd)
{
	char	*line;
	int		ct;
	int		role;

	line = NULL;
	ct = 0;
	role = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (ct == 0)
		{
			if (!(*ants = get_ants(*ants, line)))
				return (-1);
			ct++;
		}
		else if (ct == 1 && !(ft_occ_pos(line, ' ') == -1 && line[0] != '#'))
		{
			ft_printf("%s\n", line);
			if (ft_strcmp("##start", line) == 0)
				role = 1;
			else if (ft_strcmp("##end", line) == 0)
				role = -1;
			if (!(*rooms = get_room(*rooms, line, &role)))
			{
				ft_printf("PROBLEMS\n");
				return (-1);
			}
		}
		else
		{
			//if (!(*rooms = get_connections(*rooms, line)))
				return (-1);
		}
		ft_printf("LINES : %s\n", line);
		ft_strdel(&line);
	}
	return (0);
}
