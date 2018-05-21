/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 12:22:25 by mmanley           #+#    #+#             */
/*   Updated: 2018/01/05 16:53:37 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include "libft.h"

void		ft_lst_print(t_list **alst)
{
	t_list	*tmp;
	int		i;

	i = 0;
	if (alst)
	{
		tmp = *alst;
		while (tmp->next)
		{
			while (tmp->next->content)
			{
				ft_putstr(tmp->next->content);
				ft_putchar('\n');
				i++;
			}
			ft_putchar('\n');
			tmp = tmp->next;
			i = 0;
		}
	}
}
