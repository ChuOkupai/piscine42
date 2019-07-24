/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 03:08:18 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/22 04:31:55 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

static int		ft_list_size(t_list *begin_list)
{
	return ((begin_list) ? 1 + ft_list_size(begin_list->next) : 0);
}

static t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	if (!begin_list || !nbr)
		return (begin_list);
	return (ft_list_at(begin_list->next, nbr - 1));
}

void			ft_list_reverse_fun(t_list *begin_list)
{
	t_list			*right;
	void			*data;
	unsigned int	i;
	unsigned int	j;

	i = -1;
	while (begin_list && (j = ft_list_size(begin_list) - ++i) > 1)
	{
		right = ft_list_at(begin_list, j - 1);
		data = begin_list->data;
		begin_list->data = right->data;
		right->data = data;
		begin_list = begin_list->next;
	}
}
