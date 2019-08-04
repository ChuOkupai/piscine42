/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 17:33:35 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/06 17:46:50 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

// fonction qui affiche un caractere en hexadecimal
void	ft_puthex(unsigned char c)
{
	char *base;

	base = "0123456789abcdef";
	// c >> 4 recupere la dizaine
	ft_putchar(base[c >> 4]);
	// c & 0xf recupere l'unite (== c % 16)
	ft_putchar(base[c & 0xf]);
}

int	main(void)
{
	unsigned int n = 0x41424344; // "ABCD", len = 4 octets = 32 bit
	// on affiche uniquement le 'B' en hexadecimal (valeur en ascii = 66 = 42 en base 16)
	ft_puthex(n >> 16);
	ft_putchar('\n');
	// on affiche le 'B' en ascii
	ft_putchar(n >> 16);
	return (0);
}
