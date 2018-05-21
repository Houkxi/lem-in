/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 10:42:42 by mmanley           #+#    #+#             */
/*   Updated: 2018/02/05 16:47:22 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long		ft_basic_op(long n1, long n2, char op)
{
	if (op == '+')
		return (n1 + n2);
	if (op == '-')
		return (n1 - n2);
	if (op == '*')
		return (n1 * n2);
	if (op == '/')
		return (n1 / n2);
	if (op == '%')
		return (n1 % n2);
	else
		return (-n1);
}
