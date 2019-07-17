/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:09:08 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/17 17:37:01 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strswap(char **a, char **b)
{
	char *c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_sort_str_tab(char **tab, int size, int (*cmp)(char *, char *))
{
	char	*pivot;
	int		i;
	int		j;

	if (size < 2)
		return ;
	pivot = tab[--size];
	i = 0;
	j = -1;
	while (++j < size)
		if (cmp(tab[j], pivot) < 0)
			ft_strswap(&tab[i++], &tab[j]);
	if (cmp(tab[i], tab[size]) > 0)
		ft_strswap(&tab[i], &tab[size]);
	ft_sort_str_tab(tab, i, cmp);
	ft_sort_str_tab(tab + i + 1, size - i, cmp);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int n;

	n = 0;
	while (tab[n])
		n++;
	ft_sort_str_tab(tab, n, cmp);
}
