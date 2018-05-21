/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:33:37 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/20 12:28:52 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char		*spec_case(void)
{
	char		*s;

	if (!(s = (char*)malloc(sizeof(char) * 20)))
		return (NULL);
	s[19] = '\0';
	return (ft_strcpy(s, "9223372036854775808"));
}

static int		signed_count(long long int nb, int i, int base)
{
	if (nb < 0)
	{
		if (base == 10)
			i++;
		nb *= -1;
	}
	if (nb >= base)
		return (signed_count(nb / base, i + 1, base));
	return (i);
}

static int		unsigned_signed_count(unsigned long long int nb, int i, int b)
{
	if (nb >= (unsigned long long int)b)
		return (unsigned_signed_count(nb / b, i + 1, b));
	return (i);
}

char			*ft_utoall(unsigned long long int n, int base, int sz, int sg)
{
	char		*str;
	char		*us;
	int			value;

	if (base < 2 || base > 16)
		return (NULL);
	str = "0123456789ABCDEF";
	sz = unsigned_signed_count(n, 0, base) + 1;
	if (!(us = ft_strnew(sz)))
		return (NULL);
	us[sz] = '\0';
	while (sz-- > sg)
	{
		value = n % base;
		us[sz] = str[value];
		n /= base;
	}
	return (us);
}

char			*ft_itoall(long long int n, int base, int size, int *sign)
{
	char		*str;
	char		*s;
	int			value;

	if (base < 2 || base > 16)
		return (NULL);
	str = "0123456789ABCDEF";
	if (n < 0)
	{
		*sign = -2;
		n *= -1;
	}
	if (n == -9223372036854775807 - 1)
		return (spec_case());
	size = signed_count(n, 0, base) + 1;
	if (!(s = ft_strnew(size)))
		return (NULL);
	s[size] = '\0';
	while (size-- > 0)
	{
		value = n % base;
		s[size] = str[value];
		n /= base;
	}
	return (s);
}
