/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 20:42:07 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/19 02:51:11 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*begin;
	t_list	*e;
	int		i;

	begin = NULL;
	i = -1;
	while (++i < size && (e = ft_create_elem(strs[i])))
	{
		e->next = begin;
		begin = e;
	}
	return (begin);
}
