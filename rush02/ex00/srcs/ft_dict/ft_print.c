/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvernhes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 00:53:28 by hvernhes          #+#    #+#             */
/*   Updated: 2019/07/21 23:08:01 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "ft_dict.h"

void	ft_putvalue(t_list *dict, unsigned long n, int count)
{
	if (count)
		ft_putchar(' ');
	ft_putstr(ft_dict_in(dict, n)->name);
}

int		ft_special(t_list *dict, unsigned long n, int count)
{
	unsigned long i;

	i = 1000000000000;
	while ((i /= 1000) >= 1000)
		if (i == n)
			return (0);
	if (n == 100 || !ft_dict_in(dict, n))
		return (0);
	ft_putvalue(dict, n, count);
	return (1);
}

int		ft_print_digits(t_list *dict, unsigned long n, int count)
{
	if ((n %= 1000) >= 100)
	{
		ft_putvalue(dict, n / 100, count++);
		ft_putvalue(dict, 100, count);
		if (n == 100)
			return (count);
	}
	if (ft_dict_in(dict, (n %= 100)))
		ft_putvalue(dict, n, count++);
	else
	{
		if (n >= 10)
			ft_putvalue(dict, (n / 10) * 10, count++);
		if ((n %= 10))
			ft_putvalue(dict, n, count++);
	}
	return (count);
}

void	ft_print(t_list *dict, char *value)
{
	unsigned long	n;
	unsigned long	mask;
	int				count;

	while (*value == '0' && *(value + 1))
		value++;
	mask = 1000000000;
	count = 0;
	while (*value)
	{
		if (ft_special(dict, (n = ft_atol(value)), count))
			break ;
		while (mask > n + 1)
			mask /= 1000;
		count = ft_print_digits(dict, n / mask, count);
		if (mask > 1)
			ft_putvalue(dict, mask, count++);
		n = ft_strlen(value);
		value++;
		while (ft_strlen(value) % 3)
			value++;
		while (*value == '0')
			value++;
	}
	ft_putchar('\n');
}
