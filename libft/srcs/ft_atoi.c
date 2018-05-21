/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:33:57 by mmanley           #+#    #+#             */
/*   Updated: 2018/05/12 15:07:17 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				white_space_counter(char *tmp, int i, int *sign)
{
	while (tmp[i] == '\t' || tmp[i] == '\n' || tmp[i] == '\r' || tmp[i] == '\v'
			|| tmp[i] == '\f' || tmp[i] == ' ')
		i++;
	if (tmp[i] == '-' || tmp[i] == '+')
	{
		if (tmp[i] == '-')
			*sign = -1;
		i++;
	}
	return (i);
}

long long				ft_atoi(const char *str)
{
	int					i;
	long long			a;
	int					sign;
	char				*tmp;

	i = 0;
	a = 0;
	sign = 1;
	tmp = (char*)str;
	i = white_space_counter(tmp, 0, &sign);
	while (tmp[i] >= '0' && tmp[i] <= '9')
	{
		a = (a * 10) + (tmp[i] - 48);
		i++;
	}
	if (a > 9223372036854775807 && sign == -1)
		return (0);
	else if (a > 9223372036854775806 && sign == 1)
		return (-1);
	else
		return (a * sign);
}
