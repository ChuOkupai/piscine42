/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 10:25:54 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/14 21:07:52 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

void	ft_error_message(void)
{
	ft_putstr("Error\n");
}

int		main(int argc, char **argv)
{
	char	**tab;
	int		size;

	if (argc != 2 || !(size = ft_get_size(argv[1])))
		ft_error_message();
	else if ((tab = ft_init_tab(argv[1], size)))
	{
		if (ft_solve(tab, size))
			ft_print_tab(tab, size);
		ft_destroy_tab(tab, size);
	}
	else
		ft_error_message();
	return (0);
}
