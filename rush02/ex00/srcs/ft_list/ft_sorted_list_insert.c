/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 03:43:01 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/20 04:26:57 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list *e;

	if (!*begin_list || cmp(data, (*begin_list)->data) <= 0)
	{
		if (!(e = ft_create_elem(data)))
			return ;
		e->next = *begin_list;
		*begin_list = e;
	}
	else
		ft_sorted_list_insert(&(*begin_list)->next, data, cmp);
}
