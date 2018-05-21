/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:02:50 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/22 14:47:38 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

static char		*no_type(t_info *data, char **tmp)
{
	char		*t;

	t = NULL;
	data->nbr_l = 0;
	if (!(data->flgs & STOP))
	{
		*tmp && *tmp[0] == '\0' && ft_occ_pos("cC", data->type) > -1 ?
		data->nbr_l = 1 : data->nbr_l;
		*tmp && *tmp[0] != '\0' ? data->nbr_l = ft_strlen(*tmp) : data->nbr_l;
		return (*tmp);
	}
	else
	{
		t = ft_strnew(1);
		t[0] = data->type;
		data->nbr_l = 1;
		data->type == '\0' ? data->cmd_size -= 1 : data->cmd_size;
	}
	return (t);
}

t_info			*ft_printf_2(va_list *arg, char **tmp, char *s, int *x)
{
	t_info		data;
	t_info		*tp;

	data.cmd_size = -1;
	tp = NULL;
	if (s && data_init(&arg, &data, s) >= -1)
	{
		if (!(data.flgs & STOP))
		{
			data.flgs & DEC ? *tmp = nbr_manager(&arg, &data) : *tmp;
			!(data.flgs & DEC) ? *tmp = chr_manager(&arg, &data) : *tmp;
			if (*tmp == NULL)
				return (NULL);
			*tmp = no_type(&data, tmp);
		}
		else
			*tmp = no_type(&data, NULL);
		*x += data.cmd_size + 1;
		tp = &data;
		if (data.type == '\0')
			return (tp);
		flag_manager(&data, *tmp, data.nbr_l);
	}
	return (tp);
}

int				ft_printf(char *s, ...)
{
	va_list		arg;
	int			x;
	int			size;
	int			ret;
	char		*tmp;

	tmp = NULL;
	x = 0;
	ret = 0;
	if (!s || s[0] == '\0')
		return (0);
	va_start(arg, s);
	while (s[ret + x])
	{
		while (s[ret + x] && s[ret + x] != '%')
			x++;
		buff_rend(&s[ret], x, 0);
		if (s[ret + x] && !(ft_printf_2(&arg, &tmp, &s[ret + x], &x)))
			return (buff_rend(NULL, 0, -1));
		ret += x;
		x = 0;
	}
	size = buff_rend(NULL, 0, 1);
	va_end(arg);
	return (size);
}
