/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:15:12 by mmanley           #+#    #+#             */
/*   Updated: 2017/11/17 11:19:59 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_putstr(char const *str)
{
	int i;

	i = 0;
	if (str != NULL)
	{
		while (str[i])
		{
			ft_putchar(str[i]);
			i++;
		}
	}
}
