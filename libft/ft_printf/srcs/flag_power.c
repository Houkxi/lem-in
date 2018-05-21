/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_power.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 19:31:00 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/20 14:21:52 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		flag_4_chrs(t_info *data, char *s, int size)
{
	int		size2;
	int		sign;
	char	*new;

	size2 = size;
	sign = 0;
	new = ft_strdup(s);
	ft_strdel(&s);
	if (data->flgs & DOT)
	{
		new = flag_prec_chr(data->prec, new, size);
		size = ft_strlen(new);
	}
	if (data->flgs & MFIELD)
		flag_mfield_nbr(size, data, new, data->flgs);
	else
	{
		flag_sign(data, data->flgs, 0);
		buff_rend(new, size, 0);
	}
	ft_strdel(&new);
}

void		flag_4_nbrs(t_info *data, char *s, int size, unsigned int sv)
{
	int		spz;
	int		sign;
	char	*new;

	spz = 0;
	sign = 0;
	new = ft_strdup(s);
	ft_strdel(&s);
	if (sv & AP)
		new = flag_apos(new, &size, size);
	if (sv & DOT)
	{
		new = flag_prec(data->prec, new, size);
		size = ft_strlen(new);
	}
	if (sv & MFIELD)
		flag_mfield_nbr(size, data, new, data->flgs);
	else
	{
		flag_sign(data, data->flgs, 0);
		buff_rend(new, size, 0);
	}
	ft_strdel(&new);
}

static void	spec_pars(t_info **data, unsigned int sv, int size, char *s)
{
	sv & PLUS ? sv &= sv - PLUS : sv;
	sv & SPACE ? sv &= sv - SPACE : sv;
	sv & HASH ? sv &= sv - HASH : sv;
	sv & DOT ? sv &= sv - DOT : sv;
	(*data)->flgs = sv;
	flag_4_chrs(*data, s, size);
}

static void	nbr_spe_cases(t_info **data, char **s, int *size, int sv)
{
	if (*s[0] == '0' && sv & HASH && *size == 1 && (*data)->type != 'p')
	{
		if (ft_occ_pos("oO", (*data)->type) > -1)
		{
			*s[0] = '\0';
			*size = 0;
		}
		(*data)->s_ct[2] = -9;
	}
	if (*s[0] == '0' && sv & DOT && (*data)->prec == 0 && *size == 1)
	{
		(*data)->s_ct[1] = -5;
		*s[0] = '\0';
		*size = 0;
	}
	(*data)->flgs = sv;
}

void		flag_manager(t_info *data, char *s, int size)
{
	if ((ft_occ_pos("dDixXoOuUp", data->type)) > -1)
	{
		nbr_spe_cases(&data, &s, &size, data->flgs);
		fl_ps(&data, size, 0, data->flgs);
		data->flgs & HASH && ft_occ_pos("oO", data->type) > -1 ?
		data->prec -= 1 : data->prec;
		flag_4_nbrs(data, s, size, data->flgs);
	}
	else if ((ft_occ_pos("cCsS", data->type)) > -1)
	{
		if (data->flgs & DOT && data->s_ct[0] == -15 && data->prec < size)
			data->prec = size + 1;
		fl_ps(&data, size, 1, data->flgs);
		flag_4_chrs(data, s, size);
	}
	else
		spec_pars(&data, data->flgs, size, s);
}
