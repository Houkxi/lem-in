/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 18:35:48 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/20 18:46:21 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_tabcpy(char **dst, char **src)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (src[y])
	{
		while (src[y][x])
		{
			dst[y][x] = src[y][x];
			x++;
		}
		x = 0;
		y++;
	}
}
