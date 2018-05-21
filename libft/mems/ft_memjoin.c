/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 15:39:26 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/22 15:04:47 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memjoin(void *s1, void *s2, size_t len1, size_t len2)
{
	unsigned char	*cur;
	char			*new;

	cur = (unsigned char*)s1;
	if (s1 == NULL && s2 != NULL)
		return (ft_memdup(s2, len2));
	else if (s1 != NULL && s2 == NULL)
		return (ft_memdup(s1, len1));
	else if (s1 && s2)
	{
		if (!(new = (char*)malloc(len1 + len2 + 1)))
			return (NULL);
		ft_bzero(new, len1 + len2);
		ft_memcpy(new, s1, len1);
		ft_memcpy(&new[len1], s2, len2);
		new[len1 + len2] = '\0';
		return (new);
	}
	else
		return (NULL);
}
