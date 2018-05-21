/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:44:02 by mmanley           #+#    #+#             */
/*   Updated: 2018/02/15 18:23:21 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	int len;
	int i;
	int max;

	len = ft_strlen(dst);
	i = 0;
	max = size - 1;
	while (src[i] && ((len + i) < max))
	{
		dst[len + i] = src[i];
		i++;
	}
	dst[len + i] = '\0';
	if ((len + i) > max)
		return (ft_strlen(src) + size);
	return (len + ft_strlen(src));
}
