/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabint_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 16:07:22 by mmanley           #+#    #+#             */
/*   Updated: 2018/05/12 16:07:42 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			*ft_tabint_init(int ini, int size)
{
	int		i;
	int		*tab;

	i = 0;
	if (!(tab = (int*)malloc(sizeof(int) * (size + 1))))
		return (NULL);
	while (i++ < size)
		tab[i] = ini;
	return (tab);
}
