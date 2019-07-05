/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 23:22:04 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/05 16:39:37 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_puthex(unsigned char c)
{
	char *base;

	base = "0123456789abcdef";
	ft_putchar(base[c / 16]);
	ft_putchar(base[c % 16]);
}

void	ft_print_data(char *s, unsigned int size)
{
	unsigned int i;

	i = -1;
	while (++i < size)
	{
		if (!(i % 2))
			ft_putchar(' ');
		ft_puthex(s[i]);
	}
	while (i < 16)
		write(1, "   ", (i++ % 2) ? 2 : 3);
	ft_putchar(' ');
	i = -1;
	while (++i < size)
		ft_putchar((s[i] < ' ' || s[i] == 127) ? '.' : s[i]);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	int				j;

	i = 0;
	while (i < size)
	{
		ft_putchar('0');
		j = 56;
		while ((j -= 8) >= 0)
			ft_puthex((unsigned long int)(addr + i) >> j & 0xff);
		ft_putchar(':');
		ft_print_data(addr + i, (size - i < 16) ? size - i : 16);
		ft_putchar('\n');
		i += 16;
	}
	return (addr);
}
