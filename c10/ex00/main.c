/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 15:32:28 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/16 22:34:16 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft.h"

int		main(int argc, char **argv)
{
	if (argc < 2)
		ft_putstr_fd("File name missing.\n", STDERR_FILENO);
	else if (argc > 2)
		ft_putstr_fd("Too many arguments.\n", STDERR_FILENO);
	else if (ft_display_file(argv[1]) < 0)
		ft_putstr_fd("Cannot read file.\n", STDERR_FILENO);
	return (0);
}
