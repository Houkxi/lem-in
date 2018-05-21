/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:43:16 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/20 12:55:41 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*signed_nbrs(va_list ***arg, t_info **data, int base, int sg)
{
	char *save;

	save = NULL;
	if ((*data)->flgs & L)
		save = ft_itoall((long int)(va_arg(***arg, intmax_t)), base, 0, &sg);
	else if ((*data)->flgs & LL)
		save = ft_itoall((long long int)(va_arg(***arg, intmax_t)), base, 0,
		&sg);
	else if ((*data)->flgs & J)
		save = ft_itoall((intmax_t)(va_arg(***arg, intmax_t)), base, 0, &sg);
	else if ((*data)->flgs & Z)
		save = ft_itoall((size_t)(va_arg(***arg, intmax_t)), base, 0, &sg);
	else if ((*data)->flgs & H)
		save = ft_itoall((short int)(va_arg(***arg, intmax_t)), base, 0, &sg);
	else if ((*data)->flgs & HH)
		save = ft_itoall((char)(va_arg(***arg, intmax_t)), base, 0, &sg);
	else if ((*data)->flgs)
		save = ft_itoall((int)(va_arg(***arg, intmax_t)), base, 0, &sg);
	(*data)->s_ct[0] = sg;
	return (save);
}

char		*unsigned_nbrs(va_list ***arg, t_info *data, int b)
{
	char *s;

	s = NULL;
	if (data->flgs & L)
		s = ft_utoall((unsigned long int)(va_arg(***arg, uintmax_t)), b, 0, 0);
	else if (data->flgs & LL)
		s = ft_utoall((unsigned long long int)(va_arg(***arg, uintmax_t)), b, 0,
		0);
	else if (data->flgs & J)
		s = ft_utoall((uintmax_t)(va_arg(***arg, uintmax_t)), b, 0, 0);
	else if (data->flgs & Z)
		s = ft_utoall((size_t)(va_arg(***arg, uintmax_t)), b, 0, 0);
	else if (data->flgs & H)
		s = ft_utoall((unsigned short int)(va_arg(***arg, uintmax_t)), b, 0, 0);
	else if (data->flgs & HH)
		s = ft_utoall((unsigned char)(va_arg(***arg, uintmax_t)), b, 0, 0);
	else if (data->flgs)
		s = ft_utoall((unsigned int)(va_arg(***arg, uintmax_t)), b, 0, 0);
	return (s);
}

char		*nbr_manager(va_list **arg, t_info *data)
{
	char *rendu;

	rendu = NULL;
	if (data->type == 'd' || data->type == 'D' || data->type == 'i')
	{
		if (data->type == 'D' && !(data->flgs & L))
			data->flgs |= LL;
		rendu = signed_nbrs(&arg, &data, 10, 0);
	}
	else if (ft_occ_pos("uUxXoOp", data->type) > -1)
	{
		if ((data->type == 'U' || data->type == 'O') && !(data->flgs & L))
			data->flgs |= LL;
		if (data->type == 'X' || data->type == 'x' || data->type == 'p')
			rendu = unsigned_nbrs(&arg, data, 16);
		else if (data->type == 'o' || data->type == 'O')
			rendu = unsigned_nbrs(&arg, data, 8);
		else
			rendu = unsigned_nbrs(&arg, data, 10);
		if (data->type == 'x' || data->type == 'p')
			ft_put_to_lower(rendu);
	}
	else
		rendu = bonus_part(&arg, &data);
	return (rendu);
}
