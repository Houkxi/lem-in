/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:02:35 by mmanley           #+#    #+#             */
/*   Updated: 2018/05/18 11:12:29 by mmanley          ###   ########.fr       */
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
		if (!(line = get_line_check(line, fd)))
			return (NULL);
		*role = 1;
	}
	else if (ft_strcmp("##end", line) == 0)
	{
		ft_strdel(&line);
		if (!(line = get_line_check(line, fd)))
			return (NULL);
		*role = -1;
	}
	else if (coments_everywhere(line) == 2)
	{
		ft_strdel(&line);
		if (!(line = get_line_check(line, fd)))
			return (NULL);
	}
	ft_printf("**LINES : %s\n", line);
	return (line);
}
