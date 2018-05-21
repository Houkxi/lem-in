/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:44:40 by mmanley           #+#    #+#             */
/*   Updated: 2017/11/24 15:03:35 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;

	if (*alst)
	{
		while (*alst)
		{
			tmp = *alst;
			*alst = (*alst)->next;
			del(tmp->content, tmp->content_size);
			free(tmp);
		}
		*alst = NULL;
	}
}
