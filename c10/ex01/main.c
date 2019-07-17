/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 15:32:28 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/16 22:43:14 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <libgen.h>
#include <string.h>
#include "ft.h"

int		main(int argc, char **argv)
{
	char	*bin;
	int		i;

	bin = basename(argv[0]);
	if (argc < 2 && ft_display_file(NULL) < 0)
		ft_puterr(bin, NULL, strerror(errno));
	i = 0;
	while (++i < argc)
	{
		if (!ft_strcmp(argv[i], "-"))
			argv[i] = NULL;
		if (ft_display_file(argv[i]) < 0)
			ft_puterr(bin, argv[i], strerror(errno));
	}
	return (0);
}
