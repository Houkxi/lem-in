/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:27:40 by mmanley           #+#    #+#             */
/*   Updated: 2017/11/20 11:27:21 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char *s, char (*f)(char))
{
	char	*new;
	int		i;

	i = 0;
	new = NULL;
	if (s != NULL && s[i])
	{
		i = ft_strlen(s) + 1;
		if ((new = (char*)malloc(1 * i)) == 0)
			return (NULL);
		i = 0;
		while (s[i])
		{
			new[i] = f(s[i]);
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
