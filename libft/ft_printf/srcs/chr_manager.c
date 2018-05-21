/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chr_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 11:21:30 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/22 14:26:37 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*the_lone_char(va_list ***arg, t_info *data)
{
	char	*save;
	char	c;
	wchar_t	t;

	save = NULL;
	if (data->type == 'c' && !(data->flgs & L))
	{
		if (!(save = ft_strnew(2)))
			return (NULL);
		c = (char)va_arg(***arg, intmax_t);
		if (!c || c == 0)
			save[0] = '\0';
		else
			save[0] = c;
	}
	else if ((data->type == 'C' || (data->type == 'c' && data->flgs & L)))
	{
		data->s_ct[0] = -15;
		t = va_arg(***arg, wchar_t);
		if (!t || t == 0)
			save = ft_strdup("\0");
		else
			save = uni_conv(&t, data, 1, 0);
	}
	return (save);
}

char	*the_multiple_char(va_list ***arg, t_info *data)
{
	char	*save;
	wchar_t	*tmp;

	save = NULL;
	if (data->type == 's' && !(data->flgs & L))
	{
		save = va_arg(***arg, char*);
		if (save == NULL)
			save = ft_strdup("(null)");
		else
			save = ft_strdup(save);
	}
	else if ((data->type == 'S' || (data->type == 's' && data->flgs & L)))
	{
		data->type = 'S';
		data->s_ct[0] = -15;
		tmp = va_arg(***arg, wchar_t*);
		if (!tmp || (uni_size(*tmp)) == 0)
			save = ft_strdup("(null)");
		else
			save = uni_conv(tmp, data, 0, 0);
	}
	return (save);
}

char	*chr_manager(va_list **arg, t_info *data)
{
	char	*save;

	save = NULL;
	if ((save = the_lone_char(&arg, data)))
		return (save);
	else if ((save = the_multiple_char(&arg, data)))
		return (save);
	else
		save = bonus_part(&arg, &data);
	return (save);
}
