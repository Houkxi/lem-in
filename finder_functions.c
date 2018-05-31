/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 16:44:04 by mmanley           #+#    #+#             */
/*   Updated: 2018/05/31 18:06:28 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*ft_open_bridges(t_room *room)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!room)
		return (NULL);
	while (room->links[k])
		k++;
	while (room->bridge[i])
	{
		room->links[k++] = room->bridge[i];
		room->bridge[i++] = NULL;
	}
	room->nb_l = k;
	return (room);
}

int			ft_check_around(t_path *path, t_room *room)
{
	int		i;
	int		size;
	t_room	*old_rooms;

	i = 0;
	size = path->size - 1;
	if (!path || !path->links || !path->links[i])
		return (1);
	old_rooms = path->links[i];
	while (old_rooms && size--)
	{
		if (old_rooms == room)
			return (-1);
		old_rooms = path->links[++i];
	}
	return (1);
}

int			ft_find_shortest_path(t_room **links, int k, int nb_r)
{
	t_room	*room;
	int		j;
	int		nb_l;

	while (links[k])
	{
		nb_l = links[k]->nb_l;
		j = 0;
		while (nb_l--)
		{
			room = links[k]->links[j];
			if (room->len == 0)
			{
				room->len = links[k]->len + 1;
				if (room->role == -1)
					return (room->len);
				links[nb_r] = room;
				nb_r++;
			}
			j++;
		}
		k++;
	}
	return (-1);
}

t_path		*ft_close_path(t_path *path, t_path *new, int i, int k)
{
	if (!path || !path->links || !new->links)
		return (NULL);
	while (path->links[i + 1] && new->links[i + 1] && \
		path->links[i + 1] == new->links[i + 1])
		i++;
	if (i < path->size)
	{
		k = 0;
		while (path->links[i]->bridge[k])
			k++;
		path->links[i]->bridge[k] = path->links[i + 1];
		path->links[i]->nb_l--;
		k = 0;
		while (path->links[i]->links[k] && \
			path->links[i]->links[k] != path->links[i + 1])
			k++;
		while (path->links[i]->links[k + 1])
		{
			path->links[i]->links[k] = path->links[i]->links[k + 1];
			k++;
		}
		path->links[i]->links[k] = NULL;
	}
	return (path);
}

t_path		*ft_copy(t_room **links, t_path *new, int size, int len)
{
	t_room	*tmp;

	if (!new->links)
	{
		if (!(new->links = (t_room**)malloc(sizeof(t_room*) * len)))
			return (NULL);
		while (len--)
			new->links[len] = NULL;
	}
	if (!links || !links[0])
		return (NULL);
	tmp = links[0];
	while (size--)
	{
		if (tmp->nb_l == 1 && tmp->role != 1)
		{
			tmp = ft_open_bridges(tmp);
			break ;
		}
		new->links[new->size] = tmp;
		new->size += 1;
		tmp = links[new->size];
	}
	return (new);
}
