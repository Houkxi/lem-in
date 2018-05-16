/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coment_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:48:55 by mmanley           #+#    #+#             */
/*   Updated: 2018/05/16 18:20:55 by mmanley          ###   ########.fr       */
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

char				*comments(char *line, int fd)
{
	if (!line)
		return (NULL);
	while (line && coments_everywhere(line) == 1)
	{
		ft_printf("++LINES : %s\n", line);
		if (get_next_line(fd, &line) < 1)
			return (NULL);
	}
	ft_printf("TEST %s\n", line);
	return (line);
}
