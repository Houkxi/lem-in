/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:41:53 by mmanley           #+#    #+#             */
/*   Updated: 2017/11/27 11:48:41 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_putstr_fd(char const *str, int fd)
{
	int j;

	j = 0;
	if (str != NULL)
	{
		while (str[j])
		{
			ft_putchar_fd(str[j], fd);
			j++;
		}
	}
}
