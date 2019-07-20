/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 03:08:18 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/20 03:18:47 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list *prev;
	t_list *next;

	prev = NULL;
	while (begin_list)
	{
		next = begin_list->next;
		begin_list->next = prev;
		prev = begin_list;
		begin_list = next;
	}
}
