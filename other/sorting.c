/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 04:39:28 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/19 04:47:28 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int		ft_is_sorted(int *tab, int size)
{
	while (--size > 0)
		if (tab[size] < tab[size - 1])
			return (0);
		return (1);
}

void	ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int pivot;
	int i;
	int j;

	if (size < 2)
		return ;
	pivot = tab[--size];
	i = 0;
	j = -1;
	while (++j < size)
		if (tab[j] < pivot)
			ft_swap(&tab[i++], &tab[j]);
	if (tab[i] > tab[size])
		ft_swap(&tab[i], &tab[size]);
	ft_sort_int_tab(tab, i);
	ft_sort_int_tab(tab + i + 1, size - i);
}

void	ft_bubble_sort(int *tab, int size)
{
	int i, j;
	
	for (i = size - 1; i >= 0; i--)
		for (j = 1; j <= i; j++)
			if (tab[j - 1] > tab[j])
				ft_swap(&tab[j - 1], &tab[j]);
}

void	benchmark(char *name, int n, void(*sorting)(int *, int))
{
	clock_t start, end;
	int t[n];
		
	srand(0);
	for (int i = 0; i < n; i++)
		t[i] = rand();
	printf("%s:\n", name);
	start = clock();
	sorting(t, n);
	end = clock();
	printf("time: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
	//printf("sorted: %d\n", ft_is_sorted(t, n));
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	int n = atoi(argv[1]);
	if (n >= 1 && n <= 100000)
	{
		benchmark("ft_sort_int_tab", n, ft_sort_int_tab);
		benchmark("ft_bubble_sort", n, ft_bubble_sort);
	}
	return (0);
}
