/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_renderer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 10:29:33 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/22 15:04:29 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_strdel_s(char **ap, int size)
{
	if (ap != NULL && *ap)
	{
		free(*ap);
		ft_bzero(*ap, size);
		*ap = NULL;
	}
}

static int		wrong_4_smthg(char **rend, int *size, int fd)
{
	if (!*rend || *rend[0] == '\0')
		*rend = ft_strnew(1);
	write(1, *rend, *size);
	ft_strdel_s(rend, *size);
	*size = 0;
	fd = 0;
	return (-1);
}

int				buff_rend(char *s, int len, int fd)
{
	static int	size = 0;
	static char	*rend = NULL;
	char		*tmp;
	int			mlen[2];

	mlen[0] = size;
	mlen[1] = len;
	if (fd == -1)
		return (wrong_4_smthg(&rend, &size, fd));
	if (fd >= 1)
	{
		write(fd, rend, size);
		ft_strdel_s(&rend, size);
		return (size);
	}
	else
	{
		if (!rend)
			size = 0;
		tmp = ft_memdup(s, len);
		rend = ft_memjoin_free(rend, tmp, mlen, 3);
		size += len;
	}
	return (len);
}
