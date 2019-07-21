/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvernhes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 23:54:34 by hvernhes          #+#    #+#             */
/*   Updated: 2019/07/21 00:27:39 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_check_args(int argc, char **argv, char **path, char **value)
{
	if (argc < 2 || argc > 3)
	{
		*path = NULL;
		*value = NULL;
	}
	if (argc == 2)
	{
		*path = "numbers.dict";
		*value = argv[1];
	}
	else
	{
		*path = argv[1];
		*value = argv[2];
	}
}
