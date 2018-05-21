/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_chr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:05:51 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/22 14:18:28 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*flag_prec_chr(int prec, char *s, int size)
{
	char			*new;

	if (prec > size)
		prec = size;
	if ((new = (char*)malloc((prec + 1))) == NULL)
		return (NULL);
	new[prec] = '\0';
	ft_strncpy(new, s, prec);
	free(s);
	return (new);
}

void				wildcard_calc(va_list ***arg, t_info **data, int ct)
{
	int				save;
	unsigned int	sv;

	sv = (*data)->flgs;
	while (ct <= (*data)->s_ct[0])
	{
		save = va_arg(***arg, int);
		if (ct == (*data)->s_ct[1] && (*data)->mfield == -1)
		{
			(*data)->mfield = save;
			sv |= MFIELD;
			save < 0 && sv & MFIELD ? sv |= MINUS : sv;
			save < 0 ? (*data)->mfield *= -1 : (*data)->mfield;
		}
		if (ct == (*data)->s_ct[2] && (*data)->prec == -1)
		{
			(*data)->prec = save;
			(*data)->flgs |= DOT;
			save < 0 && sv & DOT ? sv &= sv - DOT : sv;
			save < 0 ? (*data)->prec = 0 : (*data)->prec;
		}
		ct++;
	}
	(*data)->flgs = sv;
}

void				new_data(t_info **data)
{
	(*data)->nbr_h = 0;
	(*data)->nbr_l = 0;
	(*data)->prec = 0;
	(*data)->mfield = 0;
	(*data)->flgs = 0;
	(*data)->cmd_size = 0;
	(*data)->type = 0;
	(*data)->s_ct[0] = 0;
	(*data)->s_ct[1] = 0;
	(*data)->s_ct[2] = 0;
}

char				*uni_trans_2(wchar_t w, char *tmp)
{
	if (w > 0x7FF && w <= 0xFFFF && tmp)
	{
		if (w >= 0xD800 && w <= 0xDFFF)
			return (NULL);
		tmp[0] = (w >> 12) + 0xE0;
		tmp[1] = ((w >> 6) & 0x3F) + 0x80;
		tmp[2] = (w & 0x3F) + 0x80;
	}
	else if (w > 0xFFFF && w <= 0x10FFFF && tmp)
	{
		tmp[0] = (w >> 18) + 0xF0;
		tmp[1] = ((w >> 12) & 0x3F) + 0x80;
		tmp[2] = ((w >> 6) & 0x3F) + 0x80;
		tmp[3] = (w & 0x3F) + 0x80;
	}
	else
		return (NULL);
	return (tmp);
}

char				*flag_apos(char *s, int *size, int try)
{
	char			*new;
	int				ct;
	int				x;

	ct = 0;
	x = 0;
	while (try > 3 && ct++ > 0)
		try /= 3;
	if (!(new = ft_strnew(*size + ct)))
		return (NULL);
	new[*size + ct] = '\0';
	ct = 0;
	try = *size;
	while (s[x])
	{
		if (try % 3 == 0 && try != *size)
			new[ct++] = ',';
		new[ct++] = s[x++];
		try--;
	}
	new[ct] = '\0';
	ft_strdel(&s);
	*size = ft_strlen(new);
	return (new);
}
