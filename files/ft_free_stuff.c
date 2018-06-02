/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 16:16:18 by mmanley           #+#    #+#             */
/*   Updated: 2018/05/31 16:38:12 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_free_map(t_map **map)
{
	if (*map)
	{
		(*map)->ants = 0;
		(*map)->nb_rooms = 0;
		(*map)->path_size = 0;
		(*map)->start = NULL;
		free((*map)->links);
		(*map)->links = NULL;
		free(*map);
		*map = NULL;
	}
}

void		ft_free_rooms(t_room **rooms)
{
	t_room	*tmp;
	int		i;

	i = 0;
	tmp = *rooms;
	if (tmp)
	{
		ft_strdel(&tmp->name);
		tmp->nb_l--;
		while (tmp->links && tmp->links[tmp->nb_l] && tmp->nb_l < 0 &&\
			tmp->nb_l--)
			tmp->links[tmp->nb_l] = NULL;
		tmp->nb_l = 0;
		tmp->len = 0;
		free(tmp->links);
		while (tmp->bridge && tmp->bridge[i])
			tmp->bridge[i++] = NULL;
		free(tmp->bridge);
		if (tmp->next)
			*rooms = tmp->next;
		free(tmp);
	}
}

int			ft_free_path(t_path **path, int nb, t_path *tmp, t_path *tmp2)
{
	if (tmp)
	{
		while (tmp->next)
		{
			if (tmp->next->next)
				tmp2 = tmp2->next;
			tmp = tmp->next;
		}
		if (tmp->yes == -1 || nb > 0)
		{
			tmp->size--;
			while (tmp->size > 0 && tmp->size--)
				tmp->links[tmp->size] = NULL;
			tmp->size = 0;
			free(tmp->links);
			tmp->links = NULL;
			free(tmp);
			if (tmp != tmp2)
				tmp2->next = NULL;
			tmp = NULL;
			return (0);
		}
	}
	return (1);
}
