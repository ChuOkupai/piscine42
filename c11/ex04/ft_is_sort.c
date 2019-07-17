/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 03:41:29 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/18 00:10:31 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int r;
	int r2;

	i = 1;
	while (i < length && !(r = f(tab[i - 1], tab[i])))
		i++;
	while (i < length)
	{
		r2 = f(tab[i - 1], tab[i]);
		if ((r < 0 && r2 > 0) || (r > 0 && r2 < 0))
			return (0);
		i++;
	}
	return (1);
}
