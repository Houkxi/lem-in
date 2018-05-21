/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:15:42 by mmanley           #+#    #+#             */
/*   Updated: 2018/05/12 14:10:05 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*cur;

	if (len == 0 || !b)
		return (b);
	cur = (unsigned char *)b;
	while (len--)
		*cur++ = (unsigned char)c;
	return (b);
}
