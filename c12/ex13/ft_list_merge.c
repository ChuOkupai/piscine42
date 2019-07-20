/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 04:09:39 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/19 05:03:46 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	if (!*begin_list1)
		*begin_list1 = begin_list2;
	else if ((*begin_list1)->next)
		ft_list_merge(&(*begin_list1)->next, begin_list2);
	else
		(*begin_list1)->next = begin_list2;
}
