/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ants_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:48:09 by mmanley           #+#    #+#             */
/*   Updated: 2018/06/01 19:21:12 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int					coments_everywhere(char *line)
{
	int				x;

	x = 0;
	if (!line)
		return (-1);
	if (line[x] && line[0] == '#')
	{
		while (line[x] && line[x] == '#')
			x++;
		if (x == 2)
			return (2);
		else
			return (1);
	}
	return (-1);
}

int					ft_check_validity(char *s)
{
	int				x;
	int				ct;
	long long int	nb;

	x = 0;
	if (s[x])
	{
		ct = ft_strlen(s);
		nb = ft_atoll(&s[x]);
		if (ft_alnumbers(s) == -1)
			return (-1);
		if (nb < 0 || nb < INT_MIN || nb > INT_MAX)
			return (-1);
		if (s[x] == '0')
			return (0);
	}
	return (0);
}

t_map				*get_ants(t_map *ants, char *line, int role, int *ct)
{
	if (!line || !*line || (ft_check_validity(line)) == -1)
		return (NULL);
	if (!(ants = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	ants->ants = ft_atoi(line);
	if (ants->ants <= 0)
	{
		free(ants);
		return (NULL);
	}
	ants->nb_rooms = 0;
	ants->path_size = -1;
	ants->start = NULL;
	ants->links = NULL;
	*ct += 1;
	return (ants);
}

void				ft_lets_print(int ant, char *room)
{
	ft_printf(LMAGENTA);
	ft_printf("L%d", ant);
	ft_printf(WHITE);
	ft_printf(BOLD);
	ft_printf("-");
	ft_printf(LCYAN);
	ft_printf("%-9s", room);
}

int					ft_heed_my_command(t_path *path, t_map *map, int k, int ro)
{
	int				i;

	while (k < map->path_size - 1)
	{
		ft_printf("\n");
		i = 1;
		while (i < ro)
		{
			if (path->links[i]->ant < map->ants && path->links[i]->open != -5)
				path->links[i]->ant = path->links[i]->ant + 1;
			else
			{
				(path->links[i]->open != -5) ? k++ : k;
				path->links[i]->open = -5;
			}
			i++;
		}
		while (--i > 0)
			if (path->links[i]->ant > 0 && path->links[i]->open != -5)
				ft_lets_print(path->links[i]->ant, path->links[i]->name);
		(ro < map->path_size) ? ro++ : ro;
	}
	return (0);
}
