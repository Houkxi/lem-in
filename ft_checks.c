/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:02:35 by mmanley           #+#    #+#             */
/*   Updated: 2018/05/16 17:49:15 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char				*ft_check_rooms(char *line, int *role, int fd)
{
	if (!line)
		return (NULL);
	if (ft_strcmp("##start", line) == 0)
	{
		ft_strdel(&line);
		get_next_line(fd, &line);
		*role = 1;
		ft_printf("**LINES : %s\n", line);
	}
	else if (ft_strcmp("##end", line) == 0)
	{
		ft_strdel(&line);
		get_next_line(fd, &line);
		*role = -1;
		ft_printf("**LINES : %s\n", line);
	}
	else if (coments_everywhere(line) == 2)
	{
		ft_strdel(&line);
		get_next_line(fd, &line);
		ft_printf("**LINES : %s\n", line);
	}
	return (line);
}
