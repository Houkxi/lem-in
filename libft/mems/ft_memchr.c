/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:09:39 by mmanley           #+#    #+#             */
/*   Updated: 2017/11/24 19:35:01 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	c1;
	size_t			i;

	i = 0;
	c1 = (unsigned char)c;
	str = (unsigned char *)s;
	while (n--)
	{
		if (str[i] == c1)
			return (str + i);
		i++;
	}
	return (NULL);
}
