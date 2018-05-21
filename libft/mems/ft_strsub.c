/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 10:04:21 by mmanley           #+#    #+#             */
/*   Updated: 2017/11/26 20:57:57 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	unsigned char	*new;
	size_t			size;
	unsigned int	count;

	if (s != NULL)
	{
		size = ft_strlen(s);
		count = 0;
		if (start + len > size)
			return (NULL);
		if ((new = (unsigned char*)malloc(sizeof(char) * (len + 1))) == NULL)
			return (NULL);
		while (s[start] && len > 0)
		{
			new[count] = s[start];
			start++;
			count++;
			len--;
		}
		new[count] = '\0';
		return ((char*)new);
	}
	return (NULL);
}
