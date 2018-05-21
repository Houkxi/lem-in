/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 10:51:30 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/20 13:48:56 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int		conv_check(unsigned int sv)
{
	if (sv & DEC)
	{
		if (sv & J)
			return (sv &= 0xFFFF80FF + J);
		else if ((sv & Z))
			return (sv &= 0xFFFF80FF + Z);
		else if ((sv & LL))
			return (sv &= 0xFFFF80FF + LL);
		else if (sv & L)
			return (sv &= 0xFFFF80FF + L);
		else if (sv & H)
			return (sv &= 0xFFFF80FF + H);
		else if (sv & HH)
			return (sv &= 0xFFFF80FF + HH);
		else
			return (sv &= 0xFFFF80FF);
	}
	else if (!(sv & DEC) && sv & L)
		return (sv = (sv & 0xFFFF00FF) + L);
	return (sv &= 0xFFFF00FF);
}

static unsigned int		conv_search(unsigned int sv, t_info **data)
{
	if ((*data)->nbr_l % 2 != 0)
		sv |= L;
	else if ((*data)->nbr_l % 2 == 0 && (*data)->nbr_l != 0)
		sv |= LL;
	else if (!(sv & L) && !(sv & LL) && !(sv & Z) &&
	(*data)->nbr_h % 2 != 0 && !(sv & J))
		sv |= H;
	else if (!(sv & L) && !(sv & LL) && !(sv & Z) &&
	(*data)->nbr_h % 2 == 0 && (*data)->nbr_h != 0 && !(sv & J))
		sv |= HH;
	return (sv);
}

void					fl_ps(t_info **data, int size, int ch, unsigned int sv)
{
	if (ch == 0)
	{
		size <= 3 && sv & AP ? sv &= sv - AP : sv;
		(*data)->s_ct[0] == -2 ? sv |= PLUS : sv;
		if (sv & MFIELD && ((*data)->mfield <= size ||
			(*data)->mfield <= (*data)->prec))
			sv &= sv - MFIELD;
		if (sv & DOT && (*data)->prec <= size && (*data)->s_ct[1] != -5)
			sv &= sv - DOT;
		sv & HASH && ((*data)->s_ct[1] == -5 || (*data)->s_ct[2] == -9) &&
		ft_occ_pos("oOp", (*data)->type) == -1 ? sv &= sv - HASH : sv;
		(sv & PLUS || sv & HASH) && sv & SPACE ? sv &= sv - SPACE : sv;
	}
	else if (ch == 1)
	{
		(*data)->s_ct[0] == -15 && sv & SPACE ? sv &= sv - SPACE : sv;
		if (sv & MFIELD && (*data)->s_ct[0] == -15 &&
		((*data)->mfield <= (*data)->prec || (*data)->mfield <= size))
			sv &= sv - MFIELD;
		(sv & DOT && (*data)->prec >= size) ||
		(sv & DOT && (*data)->type == 'c') ? sv &= sv - DOT : sv;
		if (sv & MFIELD && sv & DOT && (*data)->mfield <= (*data)->prec)
			sv &= sv - MFIELD;
	}
	(*data)->flgs = sv;
}

unsigned int			some_more_pars(t_info **data, char t, unsigned int sv)
{
	(*data)->type == 'p' ? sv |= HASH : sv;
	(*data)->type == 'p' ? sv = (sv & 0xFFFF00FF) + L : sv;
	if (ft_occ_pos("oOxXuUp", t) > -1)
	{
		sv & PLUS ? sv &= sv - PLUS : sv;
		sv & SPACE ? sv &= sv - SPACE : sv;
	}
	if (sv & AP && ft_occ_pos("xXpoO", t) > -1)
		sv &= sv - AP;
	return (sv);
}

unsigned int			pars_check(t_info **data, char t, unsigned int sv)
{
	sv = conv_search(sv, data);
	if (ft_occ_pos("dDioOxXuUp", t) > -1)
	{
		if ((sv & MINUS || sv & DOT || !(sv & MFIELD)) && sv & ZERO)
			sv &= sv - ZERO;
		(sv & PLUS || sv & HASH) && sv & SPACE ? sv &= sv - SPACE : sv;
		sv & HASH && ft_occ_pos("xXoOp", t) == -1 ? sv &= sv - HASH : sv;
		sv = some_more_pars(data, (*data)->type, sv);
		sv = conv_check(sv);
	}
	if (ft_occ_pos("cCsS", t) > -1)
	{
		sv & AP ? sv &= sv - AP : sv;
		(sv & MINUS || !(sv & MFIELD)) && sv & ZERO ? sv &= sv - ZERO : sv;
		sv & HASH ? sv &= sv - HASH : sv;
		sv & PLUS ? sv &= sv - PLUS : sv;
		sv & SPACE ? sv &= sv - SPACE : sv;
		sv = conv_check(sv);
	}
	return (sv);
}
