/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:17:38 by mmanley           #+#    #+#             */
/*   Updated: 2018/05/12 14:13:22 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static char	**tab_creator(char c, const char *s, char **tab, int i)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (s[k])
	{
		while (s[k] && s[k] == c)
			k++;
		while (s[k] && s[k] != c)
		{
			i++;
			k++;
		}
		if (i != 0)
		{
			if (!(tab[j] = ft_strnew(i)))
				return (NULL);
			j++;
			i = 0;
		}
	}
	return (tab);
}

static int	word_counter(const char *s, char c, int i, int j)
{
	while (s[i])
	{
		if (s[i] && s[i] != c)
		{
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
		while (s[i] && s[i] == c)
			i++;
	}
	return (j);
}

static void	word_cpy(char c, const char *s, char **tab, int i)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (s[k])
	{
		while (s[k] && s[k] == c)
			k++;
		while (s[k] && s[k] != c)
		{
			tab[j][i] = s[k];
			i++;
			k++;
		}
		if (i != 0)
		{
			tab[j][i] = '\0';
			j++;
			i = 0;
		}
	}
}

char		**ft_strsplit(const char *s, char c)
{
	int		counted;
	char	**tab;

	if (!s)
		return (NULL);
	counted = word_counter(s, c, 0, 0);
	if ((tab = (char**)malloc(sizeof(char*) * (counted + 1))) == 0)
		return (NULL);
	tab[counted] = NULL;
	if (!(tab_creator(c, s, tab, 0)))
	{
		ft_deltab(tab);
		return (NULL);
	}
	word_cpy(c, s, tab, 0);
	return (tab);
}
