/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:02:10 by mmanley           #+#    #+#             */
/*   Updated: 2018/01/18 12:12:44 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	ft_lstadd_end(t_list **alst, t_list *new)
{
	t_list *tmp;

	if (alst && new)
	{
		if (*alst)
		{
			tmp = *alst;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
			tmp->next->prev = tmp;
		}
	}
	else if (new)
	{
		*alst = (t_list*)malloc(sizeof(t_list));
		*alst = new;
	}
}
