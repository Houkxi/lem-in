/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 17:17:42 by mmanley           #+#    #+#             */
/*   Updated: 2018/02/14 10:52:39 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_bits(unsigned char octet, int size)
{
	int oct;

	oct = octet;
	if (size)
	{
		ft_print_bits(octet >> 1, size - 1);
		if (size % 5 == 0)
			ft_putchar(' ');
		if (oct & 1)
			ft_putchar('1');
		else
			ft_putchar('0');
	}
}
