/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 15:32:28 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/16 22:55:02 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <libgen.h>
#include <string.h>
#include "ft.h"

int		main(int argc, char **argv)
{
	char			*bin;
	int				i;
	int				count;
	unsigned int	n;

	if (argc < 3 || ft_strcmp(argv[1], "-c"))
		return (0);
	bin = basename(argv[0]);
	i = ft_atoi(argv[2]);
	n = (i < 0) ? -i : i;
	if (argc < 4 && ft_tail(NULL, n, 0, 0) < 0)
		ft_puterr(bin, NULL, strerror(errno));
	i = 2;
	count = 0;
	while (++i < argc)
	{
		if (ft_tail(argv[i], n, count, argc > 4) < 0)
			ft_puterr(bin, argv[i], strerror(errno));
		else
			count++;
	}
	return (0);
}
