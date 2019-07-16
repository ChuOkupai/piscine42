/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 21:17:48 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/16 21:28:26 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int *ret;
	int i;

	if (length < 1 || !(ret = malloc(length * sizeof(int))))
		return (NULL);
	i = -1;
	while (++i < length)
		ret[i] = f(tab[i]);
	return (ret);
}
