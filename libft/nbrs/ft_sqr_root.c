/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqr_root.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 09:54:30 by mmanley           #+#    #+#             */
/*   Updated: 2018/01/17 10:55:11 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_sqr_root(size_t nb)
{
	size_t sqr;

	sqr = 0;
	if ((int)nb < 0)
		return (0);
	while (sqr * sqr < nb)
		sqr++;
	return (sqr);
}
