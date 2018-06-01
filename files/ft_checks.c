/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanley <mmanley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:02:35 by mmanley           #+#    #+#             */
/*   Updated: 2018/06/01 15:12:45 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int					ft_alnumbers(char *s)
{
	int				x;

	x = 0;
	if (s)
	{
		while (s[x] == 32 || (s[x] >= 9 && s[x] <= 13))
			x++;
		if (s[x])
		{
			while (s[x])
			{
				if (!(s[x] >= '0' && s[x] <= '9'))
					return (-1);
				x++;
			}
			return (0);
		}
	}
	return (-1);
}

int					ft_info_checks(char **info, int ret, char *line, int *role)
{
	int				chk;

	if ((chk = coments_everywhere(line)) != -1)
	{
		if (chk == 2)
			*role = ft_check_rooms(line, *role);
		return (0);
	}
	else if (ret < 1 && ft_alnumbers(line) != -1)
		return (1);
	else if (!(ft_occ_pos(line, ' ') == -1))
	{
		info = ft_strsplit(line, ' ');
		chk = ft_tablen(info);
		if (chk == 3)
			return (ft_error(2, info, NULL));
	}
	else if (ret != 1 && (info = ft_strsplit(line, '-')))
	{
		chk = ft_tablen(info);
		if (chk == 2)
			return (ft_error(3, info, NULL));
	}
	return (ft_error(-1, info, NULL));
}

int					ft_basic_checks(char *line, int *role, int ret)
{
	int				chk;
	char			**info;

	info = NULL;
	if (!line || !line[0] || line[0] == 'L')
		return (-1);
	chk = ft_info_checks(info, ret, line, role);
	return (chk);
}

int					ft_lstlen_test(t_room *lst)
{
	int				i;

	i = 0;
	while (lst->next)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int					lst_check(t_room *rooms)
{
	t_room			*tmp;
	int				ct;

	tmp = rooms;
	ct = 0;
	while (tmp)
	{
		if (tmp->role == 1 || tmp->role == -1)
			ct++;
		tmp = tmp->next;
	}
	if (ct != 2)
		return (-1);
	else
		return (0);
}
