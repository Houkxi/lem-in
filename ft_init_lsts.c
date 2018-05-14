/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_lsts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 19:22:28 by mmanley           #+#    #+#             */
/*   Updated: 2018/05/14 20:56:14 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room			*ft_init_room(char **info, int role, int i, t_room *new_room)
{
	if (!(new_room = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	while (info[i])
	{
		if (i > 2)
		{
			ft_deltab(info);
			free(new_room);
			return (NULL);
		}
		if (i == 0)
			new_room->name = ft_strdup(info[i]);
		if (i == 1)
			new_room->x = ft_atoi(info[i]);
		if (i == 2)
			new_room->y = ft_atoi(info[i]);
		i++;
	}
	new_room->role = role;
	new_room->next = NULL;
	return (new_room);
}


t_tube		*ft_init_tubes(char *info, t_room *conct, t_room *curr)
{
	t_tube	*new;

	if (!(new = (t_tube*)malloc(sizeof(t_tube))))
		return (NULL);
	while (conct->next)
	{
		if (ft_strcmp(conct->name, info) == 0 && curr != conct)
		{
			new->tube = conct;
		}
		conct = conct->next;
	}
	new->next = NULL;
	return (new);
}

void		ft_add_concts(t_tube **alst, t_tube *new)
{
	t_tube *tmp;

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
		 	*alst = new;
	}
}
