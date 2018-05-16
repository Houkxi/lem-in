/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 14:36:24 by mmanley           #+#    #+#             */
/*   Updated: 2018/05/16 17:35:06 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_lstlen_test(t_room *lst)
{
	int		i;

	i = 0;
	while (lst->next)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_room	*ft_room_error(t_room *ptr, char **info, char *s)
{
	if (s)
		ft_printf("%s\n", s);
	if (info)
		ft_deltab(info);
	return (ptr);
}

int		ft_error(int ret, char **info, char *s)
{
	if (s)
		ft_printf("%s\n", s);
	if (info)
		ft_deltab(info);
	return (ret);
}
