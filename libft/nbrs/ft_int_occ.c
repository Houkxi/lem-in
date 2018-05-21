/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_occ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 16:05:58 by mmanley           #+#    #+#             */
/*   Updated: 2018/05/12 16:06:14 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_int_occ(int *tab, int curr, int size)
{
	int		i;

	i = 0;
	while (i++ < size)
		if (tab[i] == curr)
			return (i);
	return (-1);
}
