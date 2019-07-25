/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:22:47 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/25 13:30:01 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_abs(int n)
{
	return (n < 0) ? -n : n;
}

void	ft_solve(char *tab, int x, int *max)
{
	int i;
	int j;

	if (x == 10)
	{
		x = 0;
		while (x < 10)
			ft_putchar(tab[x++] + '0');
		ft_putchar('\n');
		(*max)++;
		return ;
	}
	i = -1;
	while (++i < 10)
	{
		j = 0;
		while (j < x && i != tab[j] && ft_abs(tab[j] - i) != x - j)
			j++;
		if (j >= x)
		{
			tab[x] = i;
			ft_solve(tab, x + 1, max);
		}
	}
}

int		ft_ten_queens_puzzle(void)
{
	char	tab[10];
	int		max;

	max = 0;
	ft_solve(tab, 0, &max);
	return (max);
}
