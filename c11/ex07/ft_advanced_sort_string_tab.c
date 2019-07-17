/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:09:08 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/18 01:06:40 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strswap(char **a, char **b)
{
	char *c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int size;
	int i;

	size = 0;
	while (tab[size])
		size++;
	while (--size >= 0)
	{
		i = 0;
		while (++i <= size)
			if (cmp(tab[i - 1], tab[i]) > 0)
				ft_strswap(&tab[i - 1], &tab[i]);
	}
}
