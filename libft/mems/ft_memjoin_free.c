/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 15:54:42 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/22 14:53:25 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memjoin_free(void *s1, void *s2, int len[2], int ch)
{
	char	*new;

	new = NULL;
	if (!(new = ft_memjoin(s1, s2, len[0], len[1])))
		return (NULL);
	if (ch == 1)
		ft_memdel(&s1);
	if (ch == 2)
		ft_memdel(&s2);
	if (ch == 3)
	{
		ft_memdel(&s1);
		ft_memdel(&s2);
	}
	return (new);
}
