/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ants_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:48:09 by mmanley           #+#    #+#             */
/*   Updated: 2018/06/01 11:39:50 by mmanley          ###   ########.fr       */
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

int					ft_heed_my_command(t_path *path, t_map *map)
{
	return (0);
}
