/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ants_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:48:09 by mmanley           #+#    #+#             */
/*   Updated: 2018/05/16 18:46:48 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int					ft_check_validity(char *s)
{
	int				x;
	int				ct;
	long long int	nb;

	x = 0;
	ct = ft_strlen(s);
	if (ft_atoi(&s[x]) <= 0)
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


t_map		*get_ants(t_map *ants, char *line)
{
	if (!line || !*line || (ft_check_validity(line)) == -1)
	{
		ft_printf("No ants ... PUT SOME !!!\n");
		return (NULL);
	}
	if (!(ants = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	ants->nb = ft_atoi(line);
	ants->nb_r = 0;
	ants->strt = NULL;
	return (ants);
}

t_map		*checking_ants(t_map *ants, char **line, int *ct, int fd)
{
	char	*new;

	new = *line;
	if (*ct == 0 && *line[0] != '#')
	{
		ft_printf("ANTS ->LINES : %s\n", *line);
		if (!(ants = get_ants(ants, *line)))
			return (NULL);
		get_next_line(fd, &new);
		*line = new;
		*ct += 1;
	}
	return (ants);
}
