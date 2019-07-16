/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 13:05:13 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/14 19:55:00 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_height_col(char **tab, int x, int delta, int size)
{
	int y;
	int max;
	int vmax;
	int height;

	y = (delta > 0) ? 0 : size - 1;
	max = (delta > 0) ? size : -1;
	vmax = 0;
	height = 0;
	while (y != max)
	{
		if (!tab[y][x])
			return (0);
		if (tab[y][x] > vmax)
		{
			vmax = tab[y][x];
			height++;
		}
		y += delta;
	}
	return (height);
}

int	ft_height_row(char **tab, int y, int delta, int size)
{
	int x;
	int max;
	int vmax;
	int height;

	x = (delta > 0) ? 0 : size - 1;
	max = (delta > 0) ? size : -1;
	vmax = 0;
	height = 0;
	while (x != max)
	{
		if (tab[y][x] > vmax)
		{
			vmax = tab[y][x];
			height++;
		}
		x += delta;
	}
	return (height);
}

int	ft_is_duplicate(char **tab, int x, int y, int size)
{
	int i;

	if (!tab[y][x])
		return (0);
	i = y;
	while (i--)
		if (tab[y][x] == tab[i][x])
			return (1);
	i = y;
	while (++i < size)
		if (tab[y][x] == tab[i][x])
			return (1);
	i = x;
	while (i--)
		if (tab[y][x] == tab[y][i])
			return (1);
	i = x;
	while (++i < size)
		if (tab[y][x] == tab[y][i])
			return (1);
	return (0);
}
