/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rec_power.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:54:15 by mmanley           #+#    #+#             */
/*   Updated: 2018/02/14 15:54:33 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_rec_power(int nb, int power)
{
	if (power == 0)
		return (1);
	if (power > 0)
		return (nb * ft_rec_power(nb, power - 1));
	else
		return (0);
}
