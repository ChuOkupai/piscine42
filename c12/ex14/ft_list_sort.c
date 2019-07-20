/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 04:32:07 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/19 07:02:31 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_merge(t_list *l1, t_list *l2, int (*cmp)())
{
	if (!l1)
		return (l2);
	if (!l2)
		return (l1);
	if (cmp(l1->data, l2->data) > 0)
	{
		l2->next = ft_merge(l1, l2->next, cmp);
		return (l2);
	}
	l1->next = ft_merge(l1->next, l2, cmp);
	return (l1);
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list *prev;
	t_list *next;

	if (!*begin_list || !(*begin_list)->next)
		return ;
	prev = *begin_list;
	next = prev->next;
	while (next && (next = next->next))
	{
		prev = prev->next;
		next = next->next;
	}
	next = prev->next;
	prev->next = NULL;
	ft_list_sort(&(*begin_list), cmp);
	ft_list_sort(&next, cmp);
	*begin_list = ft_merge(*begin_list, next, cmp);
}
