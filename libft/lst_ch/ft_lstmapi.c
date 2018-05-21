/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:37:54 by mmanley           #+#    #+#             */
/*   Updated: 2017/12/07 11:13:21 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmapi(t_list *lst, t_list *(*f)(int i, t_list *elem), int i)
{
	t_list	*new;

	if (lst && f)
	{
		new = f(i, lst);
		lst = lst->next;
		if (lst)
			new = ft_lstmapi(lst, f, i + 1);
		return (new);
	}
	return (NULL);
}
