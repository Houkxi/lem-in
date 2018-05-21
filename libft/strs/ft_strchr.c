/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:52:11 by mmanley           #+#    #+#             */
/*   Updated: 2018/02/02 14:44:12 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	test;

	i = 0;
	test = c;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == test)
			return ((char*)str + i);
		i++;
	}
	if (str[i] == c)
		return ((char*)str + i);
	else
		return (NULL);
}
