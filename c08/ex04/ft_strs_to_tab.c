/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 11:52:29 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/12 11:12:38 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

char				*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	dest = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*t;
	int			i;

	if (ac < 0)
		ac = 0;
	if (!(t = malloc((ac + 1) * sizeof(t_stock_str))))
		return (NULL);
	i = -1;
	while (++i < ac)
	{
		t[i].size = ft_strlen(av[i]);
		t[i].str = av[i];
		t[i].copy = ft_strdup(av[i]);
	}
	t[i].str = 0;
	return (t);
}
