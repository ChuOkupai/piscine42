/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 03:08:37 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/20 03:02:35 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*free_fct)(void *))
{
	t_list *prev;
	t_list *l;

	prev = NULL;
	l = *begin_list;
	while (l)
		if (!cmp(l->data, data_ref))
		{
			if (prev)
				prev->next = l->next;
			else
				*begin_list = l->next;
			if (free_fct)
				free_fct(l->data);
			free(l);
			l = (prev) ? prev->next : *begin_list;
		}
		else
		{
			prev = l;
			l = l->next;
		}
}
