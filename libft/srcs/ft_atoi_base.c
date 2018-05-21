/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:17:56 by mmanley           #+#    #+#             */
/*   Updated: 2018/02/14 15:54:26 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	power_pos(char *s, char *base)
{
	int		x;

	x = 0;
	while (s[x] && ft_occ_pos(base, s[x]) != -1)
		x++;
	return (x);
}

int			ft_atoi_base(char *s, char *base)
{
	int		x;
	int		nb;
	int		sign;
	int		base_len;
	int		power;

	x = 0;
	sign = 1;
	base_len = ft_strlen(base);
	nb = 0;
	while (s[x] && s[x] >= 0 && s[x] <= 32)
		x++;
	if (s[x] && s[x] == '-')
		sign = -1;
	if (s[x] && (s[x] == '-' || s[x] == '+'))
		x++;
	power = power_pos(&s[x], base);
	while (power > 0)
	{
		nb += (ft_occ_pos(base, s[x]) * (ft_rec_power(base_len, --power)));
		x++;
	}
	return (nb * sign);
}
