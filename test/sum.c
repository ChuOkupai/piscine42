/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 23:19:13 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/08 23:29:35 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	sum(int n)
{
	if (n < 1)
		return (0);
	return (n + sum(n - 1));
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("%d", sum(atoi(argv[1])));
	return (0);
}
