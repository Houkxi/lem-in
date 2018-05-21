/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 12:14:54 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/20 18:49:27 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				star_spe(char *s, t_info ****data, int x)
{
	(***data)->s_ct[0]++;
	if (s[x - 1] == '.')
	{
		(***data)->s_ct[2] = (***data)->s_ct[0];
		(***data)->prec = -1;
	}
	else
	{
		(***data)->s_ct[1] = (***data)->s_ct[0];
		(***data)->mfield = -1;
	}
}

static	unsigned int	basc(char *s, unsigned int sv, t_info ***data, int *xb)
{
	s[*xb] && s[*xb] == 'l' ? (**data)->nbr_l += 1 : (**data)->nbr_l;
	s[*xb] && s[*xb] == 'h' ? (**data)->nbr_h += 1 : (**data)->nbr_h;
	s[*xb] && s[*xb] == 'j' ? sv |= J : sv;
	s[*xb] && s[*xb] == 'z' ? sv |= Z : sv;
	s[*xb] && s[*xb] == '-' ? sv |= MINUS : sv;
	s[*xb] && s[*xb] == '+' ? sv |= PLUS : sv;
	s[*xb] && s[*xb] == '#' ? sv |= HASH : sv;
	s[*xb] && s[*xb] == ' ' ? sv |= SPACE : sv;
	s[*xb] && s[*xb] == '\'' ? sv |= AP : sv;
	return (sv);
}

static unsigned int		fcn(char *s, unsigned int sv, t_info ***data, int *x)
{
	s[*x] && s[*x] == '0' && (s[*x - 1] <= '0' || s[*x - 1] > '9')
	? sv |= ZERO : sv;
	if (s[*x] && s[*x + 1] && s[*x] == '.')
	{
		while (ft_occ_pos(".0123456789", s[*x]) > -1)
		{
			if (s[*x] == '.')
				(**data)->prec = *x;
			*x += 1;
		}
		sv |= DOT;
	}
	if (s[*x] && s[*x] == '*')
		star_spe(s, &data, *x);
	if (s[*x] && s[*x] > '0' && s[*x] <= '9' && (s[*x - 1] != '.' &&
	(s[*x - 1] <= '0' || s[*x - 1] > '9')))
	{
		(**data)->mfield = ft_atoi(&s[*x]);
		*x += rec_nbr_count((**data)->mfield, 0, 10);
		sv |= MFIELD;
	}
	return (sv);
}

static char				type_check(char *s, t_info **data)
{
	int					x;
	int					ret;
	char				*type;

	x = 0;
	type = "dDioOxXuUpbBcCsSt %#*0+-'.hjzlL$123456789q_";
	while (s[x] && (ret = ft_occ_pos(type, s[x])) > 16 && ++x)
	{
		(*data)->flgs = fcn(s, (*data)->flgs, &data, &x);
		(*data)->flgs = basc(s, (*data)->flgs, &data, &x);
		if (s[x] && x != 0 && s[x] == '%')
		{
			ret = 18;
			break ;
		}
	}
	if (ret >= 0 && ret <= 11)
		(*data)->flgs |= DEC;
	(*data)->type = s[x];
	if (ret == -1 || ret > 16)
		(*data)->flgs |= STOP;
	return (x);
}

int						data_init(va_list **arg, t_info *data, char *s)
{
	int					ct;

	ct = 1;
	new_data(&data);
	data->cmd_size = type_check(s, &data);
	if (data->flgs & DOT && data->prec != -1)
		data->prec = ft_atoi(&s[data->prec + 1]);
	wildcard_calc(&arg, &data, 1);
	if (data->flgs & STOP)
		return (-1);
	data->flgs = pars_check(&data, data->type, data->flgs);
	return (0);
}
