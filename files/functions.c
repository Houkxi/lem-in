/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 14:36:24 by mmanley           #+#    #+#             */
/*   Updated: 2018/05/31 11:05:13 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_lstlen_test(t_room *lst)
{
	int		i;

	i = 0;
	while (lst->next)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void		ft_exit(t_room **rooms, t_map **map, t_path **path, char *s, int s2)
{
	ft_printf("WANT TO EXIT PLEASE!!\n");
	ft_printf("N --> %d\n", s2);
	if (rooms && *rooms)
		while ((*map)->nb_rooms--)
			ft_free_rooms(&(*rooms));
	if (path && *path)
		ft_free_path(&(*path), 4);
	if (map && *map)
	{
		ft_printf("Works");
		free(*map);
		*map = NULL;
	}
	exit (1);
}

t_room		*ft_room_error(t_room *ptr, char **info, char *s)
{
	if (s)
		ft_printf("%s\n", s);
	if (info)
		ft_deltab(info);
	return (ptr);
}

int			ft_error(int ret, char **info, char *s)
{
	if (s)
		ft_printf("%s\n", s);
	if (info)
		ft_deltab(info);
	return (ret);
}

int			ft_error_str(int ret, char *info, char *s)
{
	if (s)
		ft_printf("%s\n", s);
	if (info)
		ft_strdel(&info);
	return (ret);
}

char		*get_line_check(char *line, int fd)
{
	ft_strdel(&line);
	if (get_next_line(fd, &line) < 1)
		return (NULL);
	if (!line || !line[0] || line[0] == 'L')
	{
		ft_printf("Error in new line\n");
		return (NULL);
	}
	return (line);
}

int			lst_check(t_room *rooms)
{
	t_room	*tmp;
	int		ct;

	tmp = rooms;
	ct = 0;
	while (tmp)
	{
		if (tmp->role == 1 || tmp->role == -1)
			ct++;
		tmp = tmp->next;
	}
	if (ct != 2)
		return (-1);
	else
		return (0);
}
