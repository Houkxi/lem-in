/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab_preci.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 10:50:25 by mmanley           #+#    #+#             */
/*   Updated: 2018/03/16 13:22:47 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include "libft.h"

void	ft_show_tab_preci(int **tab, int sizey, int sizex, int pre)
{
	int k;
	int j;
	int pr;

	k = 0;
	j = 0;
	pr = 0;
	if (tab)
	{
		while (k < sizey)
		{
			while (j < sizex)
			{
				pr = rec_nbr_count(tab[k][j], 0, 10);
				ft_putnbr(tab[k][j]);
				while (pr++ < pre)
					ft_putchar(' ');
				j++;
				pr = 0;
			}
			ft_putchar('\n');
			j = 0;
			k++;
		}
	}
}
