/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_biggest_square.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 09:30:32 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/24 21:00:55 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_compute(t_map *m, t_square *s, int *t, t_point p)
{
	int tmp;
	int u;

	u = 0;
	p.y = 0;
	while (++p.y <= m->size.y)
	{
		p.x = 0;
		while (++p.x <= m->size.x)
		{
			tmp = t[p.x];
			if (m->matrix[p.x - 1 + (p.y - 1) * (1 + m->size.x)] == m->empty)
			{
				t[p.x] = MIN(MIN(u, t[p.x - 1]), t[p.x]) + 1;
				if (s->size < t[p.x])
				{
					s->coords = p;
					s->size = t[p.x];
				}
			}
			else
				t[p.x] = 0;
			u = tmp;
		}
	}
}

void	ft_find_biggest_square(t_map *m, t_square *s)
{
	t_point	p;
	int		tab[m->size.x + 1];

	s->size = 0;
	p.x = 0;
	while (p.x <= m->size.x)
		tab[p.x++] = 0;
	ft_compute(m, s, tab, p);
	p.y = s->coords.y;
	s->coords.y -= s->size;
	s->coords.x -= s->size;
	while (p.y > s->coords.y)
	{
		p.y--;
		p.x = s->coords.x + s->size;
		while (p.x > s->coords.x)
		{
			p.x--;
			m->matrix[p.x + p.y * (1 + m->size.x)] = m->full;
		}
	}
}
