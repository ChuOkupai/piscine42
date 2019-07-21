/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 15:32:28 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/21 23:16:48 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"
#include "ft_dict.h"

int		main(int argc, char **argv)
{
	t_list	*dict;
	char	*path;
	char	*value;
	char	*content;

	ft_check_args(argc, argv, &path, &value);
	if (!ft_is_valid(value))
		ft_putstr("Error\n");
	else if ((content = ft_file_load(path)))
	{
		dict = ft_dict_create(content);
		free(content);
		if (dict)
		{
			ft_print(dict, value);
			ft_list_clear(dict, &ft_dict_clear);
		}
	}
	else
		ft_putstr("Dict Error\n");
	return (0);
}
