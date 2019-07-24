/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 09:25:05 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/24 18:20:54 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft.h"

int		ft_atoui(char *str, int *length)
{
	long	res;
	int		i;

	res = 0;
	*length = 0;
	while (str[*length] >= '0' && str[*length] <= '9')
		(*length)++;
	i = 0;
	while (str[*length + i] && str[*length + i] != '\n')
		i++;
	if (i > 3)
		return (0);
	*length -= 3 - i;
	i = 0;
	while (i < *length)
	{
		res = res * 10 + str[i++] - '0';
		if (res > INT_MAX)
		{
			res = 0;
			break ;
		}
	}
	return ((res > 16000) ? 0 : res);
}

int		ft_check_line(t_map *m)
{
	char	*s;
	t_point	p;

	s = m->matrix;
	p.x = -1;
	while (s[++p.x] != '\n')
		if (!s[p.x] || s[p.x] == m->full
			|| (s[p.x] != m->empty && s[p.x] != m->obstacle))
			return (0);
	m->size.x = p.x;
	p.y = 1;
	while (m->size.x == p.x++ && *(s += p.x))
	{
		p.x = -1;
		while (s[++p.x] != '\n')
			if (!s[p.x] || s[p.x] == m->full || (s[p.x] != m->empty
				&& s[p.x] != m->obstacle))
				return (0);
		p.y++;
	}
	return (p.y == m->size.y);
}

int		ft_is_valid(t_map *m)
{
	int i;

	if ((m->size.y = ft_atoui(m->content, &i)) <= 0)
		return (0);
	if (m->content[i] != '\0' && m->content[i] != '\n')
		m->empty = m->content[i++];
	else
		return (0);
	if (m->content[i] != '\0' && m->content[i] != '\n')
		m->obstacle = m->content[i++];
	else
		return (0);
	if (m->content[i] != '\0' && m->content[i] != '\n')
		m->full = m->content[i++];
	else
		return (0);
	if (m->content[i] != '\n' || m->empty == m->full || m->empty == m->obstacle
		|| m->full == m->obstacle)
		return (0);
	m->matrix = m->content + i + 1;
	return (ft_check_line(m));
}
