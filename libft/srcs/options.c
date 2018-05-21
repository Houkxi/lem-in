/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <exam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 10:32:46 by exam              #+#    #+#             */
/*   Updated: 2018/05/12 14:56:25 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		power(int power)
{
	int			i;

	i = 1;
	if (power == 0)
		return (1);
	while (power--)
		i *= 2;
	return (i);
}

static int		ft_occ(char *s, char c)
{
	int			x;

	x = 0;
	while (s[x])
	{
		if (s[x] == c)
			return (x);
		x++;
	}
	if (s[x] == c)
		return (x);
	return (-1);
}

static char			*options(char *s, int *oct)
{
	int			x;
	int			ret;

	x = 1;
	ret = 0;
	if (s[0] != '-')
		return (s);
	s[0] = ' ';
	while (s[x])
	{
		ret = ft_occ("abcdefghijklmnopqrstuvwxyz", s[x]);
		if (ret == -1)
			return (NULL);
		s[x] = ' ';
		ret = power(ret);
		*oct |= ret;
		x++;
	}
	return (s);
}

char			**option_check(char **av, int ac, int *opt)
{
	int			sv;
	int			i;

	i = 1;
	sv = 0;
	while (i < ac)
	{
		if (av[i][0] == '-' && !(av[i] = options(av[i], &sv)))
		{
			write(2, "Error\n", 6);
			ft_printf("Usage: exe [abcdefghijklmnopqrstuvwxyz]\n");
			return (NULL);
		}
		i++;
	}
	*opt = sv;
	return (av);
}
