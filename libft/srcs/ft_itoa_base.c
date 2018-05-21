/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:49:57 by mmanley           #+#    #+#             */
/*   Updated: 2018/02/05 16:47:40 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_rec_count(long nb, int i, int base)
{
	if (nb < 0)
	{
		if (base == 10)
			i++;
		nb *= -1;
	}
	if (nb >= base)
		return (ft_rec_count(nb / base, i + 1, base));
	return (i);
}

static char	*cpy_it(long n, int size, int base, int sign)
{
	char	*str;
	char	*s;
	int		value;

	str = "0123456789ABCDEF";
	if ((s = (char*)malloc(size + 1)) == NULL)
		return (NULL);
	s[size] = '\0';
	if (base == 10 && sign == 1)
		s[0] = '-';
	while (size-- > sign)
	{
		value = n % base;
		s[size] = str[value];
		n /= base;
	}
	return (s);
}

char		*ft_itoa_base(int value, int base)
{
	char	*s;
	long	n;
	int		sign;
	int		size;

	sign = 0;
	n = value;
	if (base < 2 || base > 16)
		return (NULL);
	size = ft_rec_count(n, 0, base) + 1;
	if (n < 0)
	{
		if (base == 10)
			sign = 1;
		n *= -1;
	}
	s = cpy_it(n, size, base, sign);
	return (s);
}
