/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 15:48:54 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/13 15:54:04 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memdup(void *s, size_t len)
{
	char	*new;

	if (s)
	{
		if (!(new = (char*)malloc(len + 1)))
			return (NULL);
		ft_memcpy(new, s, len);
		new[len] = '\0';
		return (new);
	}
	return (NULL);
}
