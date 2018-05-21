/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 10:50:25 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/19 15:00:41 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include "libft.h"

void	ft_show_tab(char **tab)
{
	int k;

	k = 0;
	if (tab)
	{
		while (tab[k])
		{
			ft_putstr(tab[k]);
			ft_putchar('\n');
			k++;
		}
	}
	ft_putchar('\n');
}
