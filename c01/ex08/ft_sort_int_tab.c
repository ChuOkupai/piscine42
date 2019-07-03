/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 03:27:57 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/03 04:33:21 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
