/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 10:48:54 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/14 21:19:00 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

int	ft_is_valid_value(char **tab, int x, int y, int size)
{
	if (ft_is_duplicate(tab, x, y, size)
		|| ft_height_col(tab, x, 1, size) > tab[x][size] || (y == size - 1
		&& ft_height_col(tab, x, -1, size) != tab[x][size + 1])
		|| ft_height_row(tab, y, 1, size) > tab[y][size + 2] || (x == size - 1
		&& ft_height_row(tab, y, -1, size) != tab[y][size + 3]))
		return (0);
	return (1);
}

int	ft_backtrack(char **tab, int n, int size)
{
	int i;
	int x;
	int y;

	if (n == size * size)
		return (1);
	i = 0;
	x = n % size;
	y = n / size;
	while (++i <= size)
	{
		tab[y][x] = i;
		if (ft_is_valid_value(tab, x, y, size))
		{
			if (ft_backtrack(tab, n + 1, size))
				return (1);
			tab[y][x] = 0;
		}
	}
	tab[y][x] = 0;
	return (0);
}

int	ft_solve(char **tab, int size)
{
	int i;

	i = -1;
	while (++i < size)
		if (tab[i][size] + tab[i][size + 1] > size + 1
			|| tab[i][size + 2] + tab[i][size + 3] > size + 1)
			return (0);
	return (ft_backtrack(tab, 0, size));
}
