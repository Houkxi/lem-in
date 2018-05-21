/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 10:50:25 by mmanley           #+#    #+#             */
/*   Updated: 2018/02/05 19:05:51 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include "libft.h"

void	ft_show_tab_int(int **tab, int sizey, int sizex)
{
	int k;
	int j;

	k = 0;
	j = 0;
	if (tab)
	{
		while (k < sizey)
		{
			while (j < sizex)
			{
				ft_putnbr(tab[k][j]);
				ft_putchar(' ');
				j++;
			}
			ft_putchar('\n');
			j = 0;
			k++;
		}
	}
}
