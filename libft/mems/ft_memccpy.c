/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:35:57 by mmanley           #+#    #+#             */
/*   Updated: 2017/11/17 11:18:47 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			to_find;
	char			*srcs;
	unsigned char	*dest;
	size_t			i;

	to_find = (char)c;
	srcs = (char*)src;
	dest = (unsigned char*)dst;
	i = 0;
	while (i < n)
	{
		dest[i] = srcs[i];
		if (srcs[i] == to_find)
			return ((void*)(dst + i + 1));
		i++;
	}
	return (NULL);
}
