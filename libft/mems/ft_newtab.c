/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newtab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:03:19 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/07 14:01:52 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	**ft_newtab(int yaxis, int xaxis, char c)
{
	char	**tab;
	int		k;
	int		j;

	k = 0;
	j = 0;
	if ((tab = (char**)malloc(sizeof(char*) * (yaxis + 1))) == 0)
		return (NULL);
	tab[yaxis] = NULL;
	while (k < yaxis)
	{
		if ((tab[k] = (char*)malloc(sizeof(char) * (xaxis + 1))) == 0)
			return (NULL);
		tab[k][xaxis] = '\0';
		while (j < xaxis)
		{
			tab[k][j] = c;
			j++;
		}
		j = 0;
		k++;
	}
	return (tab);
}
