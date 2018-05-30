/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ants_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:48:09 by mmanley           #+#    #+#             */
/*   Updated: 2018/05/30 18:02:43 by mmanley          ###   ########.fr       */
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
	return (x);
}

int					ft_check_validity(char *s)
{
	int				x;
	int				ct;
	long long int	nb;

	x = 0;
	ct = ft_strlen(s);
	if (s[x] == '0')
		return (0);
	if (ft_atoi(&s[x]) < 0)
		return (-1);
	if (s[x])
	{
		while (s[x] == 32 || (s[x] >= 9 && s[x] <= 13))
			x++;
		if (s[x] == '+')
			x++;
		if (x == 0 || x == 1)
			while (s[x] && s[x] == '0')
				x++;
		nb = ft_atoi(&s[x]);
		if (nb < 0)
			nb *= -1;
		if (ct - x != rec_nbr_count(nb, 1, 10))
			return (-1);
	}
	return (0);
}

t_map				*get_ants(t_map *ants, char *line)
{
	if (!line || !*line || (ft_check_validity(line)) == -1)
	{
		ft_printf("No ants ... PUT SOME !!!\n");
		return (NULL);
	}
	if (!(ants = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	ants->ants = ft_atoi(line);
	ants->nb_rooms = 0;
	ants->path_size = -1;
	ants->start = NULL;
	ants->links = NULL;
	return (ants);
}

int					ft_heed_my_command(t_path *path, t_map *map)
{
	return (0);
}
