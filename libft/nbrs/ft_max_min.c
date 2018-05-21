/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:52:25 by mmanley           #+#    #+#             */
/*   Updated: 2018/01/18 18:58:50 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_max_min(double a, double b, char *str)
{
	double res;

	res = a - b;
	if (ft_strcmp(str, "min") == 0)
	{
		if (a < b)
			return (a);
		else if (b < a)
			return (b);
	}
	if (ft_strcmp(str, "max") == 0)
	{
		if (a > b)
			return (a);
		else if (b > a)
			return (b);
	}
	return (0);
}
