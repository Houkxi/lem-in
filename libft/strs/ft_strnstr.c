/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:26:51 by mmanley           #+#    #+#             */
/*   Updated: 2017/11/24 17:28:45 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = len;
	while (haystack[i] && needle[i] && haystack[i] == needle[i] && j != 0)
	{
		i++;
		j--;
	}
	if (len == 0 && needle[i])
		return (0);
	if (!needle[i])
		return ((char*)haystack);
	if (!haystack[i])
		return (0);
	return (ft_strnstr((char*)haystack + 1, needle, len - 1));
}
