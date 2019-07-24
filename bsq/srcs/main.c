/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 15:32:28 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/24 18:15:04 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft.h"

static void	ft_bsq(char *path)
{
	t_map		map;
	t_square	square;
	int			y;

	if (!(map.content = ft_file_load(path))
		|| !ft_is_valid(&map))
		write(STDERR_FILENO, "map error\n", 10);
	else
	{
		ft_find_biggest_square(&map, &square);
		map.size.x++;
		y = 0;
		while (y < map.size.y)
			write(STDOUT_FILENO, map.matrix + map.size.x * y++, map.size.x);
	}
	free(map.content);
}

int			main(int argc, char **argv)
{
	char	c;
	int		i;

	if (argc < 2)
	{
		ft_bsq(NULL);
		return (0);
	}
	c = '\n';
	i = 0;
	while (++i < argc)
	{
		if (i > 1)
			write(STDOUT_FILENO, &c, 1);
		ft_bsq(argv[i]);
	}
	return (0);
}
