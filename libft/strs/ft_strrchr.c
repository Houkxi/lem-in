/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:57:46 by mmanley           #+#    #+#             */
/*   Updated: 2017/11/20 14:21:48 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	test;

	i = 0;
	test = c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == test)
			return ((char*)s + i);
		i--;
	}
	if (s[i] == c)
		return ((char*)s + i);
	else
		return (0);
}
