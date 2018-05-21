/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_pmss.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 17:47:28 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/19 14:18:35 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			flag_sign(t_info *data, unsigned int sv, int ret)
{
	if (!(sv & PLUS) && !(sv & SPACE) && !(sv & HASH))
		return (0);
	if (sv & PLUS)
	{
		if (data->s_ct[0] == -2)
			ret += buff_rend("-", 1, 0);
		else
			ret += buff_rend("+", 1, 0);
	}
	else if (sv & SPACE)
		ret += buff_rend(" ", 1, 0);
	else if (sv & HASH)
	{
		if (data->type == 'x' || data->type == 'p')
			ret += buff_rend("0x", 2, 0);
		else if (data->type == 'X')
			ret += buff_rend("0X", 2, 0);
		else if (data->type == 'o' || data->type == 'O')
			ret += buff_rend("0", 1, 0);
		else
			ret = 0;
	}
	return (ret);
}

char		*flag_prec(int prec, char *s, int size)
{
	char	*new;

	if ((new = (char*)malloc((prec + 1))) == NULL)
		return (NULL);
	ft_bzero(new, prec);
	new[prec] = '\0';
	if (prec <= size)
	{
		new = ft_strcpy(new, s);
		ft_strdel(&s);
		return (new);
	}
	while (size >= 0)
	{
		new[prec] = s[size];
		prec--;
		size--;
	}
	while (prec >= 0)
		new[prec--] = '0';
	ft_strdel(&s);
	return (new);
}

char		*flag_hash(int size, char *s, t_info *data)
{
	int		add;
	char	*new;

	if (data->type == 'x' || data->type == 'X' || data->type == 'p')
		add = 2;
	else
		add = 1;
	if ((new = (char*)malloc((size + add + 1))) == NULL)
		return (NULL);
	new[size + add] = '\0';
	if (data->type == 'x' || data->type == 'p')
		new = ft_strncpy(new, "0x", 2);
	else if (data->type == 'X')
		new = ft_strncpy(new, "0X", 2);
	else if (data->type == 'o' || data->type == 'O')
		new = ft_strncpy(new, "0", 1);
	new = ft_strncat(new, s, size);
	free(s);
	return (new);
}

static void	mfielding(int len, char c)
{
	char	*new;
	int		size;

	size = len;
	if (len <= 0)
		return ;
	if (!(new = ft_strnew(len + 1)))
		return ;
	new[len] = '\0';
	while (len--)
		new[len] = c;
	buff_rend(new, size, 0);
	free(new);
}

void		flag_mfield_nbr(int size, t_info *data, char *s, unsigned int sv)
{
	int		mfield;

	mfield = data->mfield;
	if (sv & MINUS)
	{
		mfield -= flag_sign(data, data->flgs, 0);
		buff_rend(s, size, 0);
		mfielding(mfield - size, ' ');
	}
	else if (sv & ZERO)
	{
		mfield -= flag_sign(data, data->flgs, 0);
		mfielding(mfield - size, '0');
		buff_rend(s, size, 0);
	}
	else
	{
		sv & PLUS || sv & SPACE || sv & HASH ? mfield-- : mfield;
		if ((ft_occ_pos("xXp", data->type)) > -1 && sv & HASH)
			mfield--;
		mfielding(mfield - size, ' ');
		flag_sign(data, data->flgs, 0);
		buff_rend(s, size, 0);
	}
}
