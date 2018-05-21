/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 17:17:42 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/12 19:22:17 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_print_bits_int(unsigned int octet, int size)
{
	int oct;

	oct = octet;
	if (size)
	{
		ft_print_bits_int(octet >> 1, size - 1);
		ft_putchar('0' + (oct & 1));
		if (size % 8 == 0)
			ft_putchar(' ');
	}
}
