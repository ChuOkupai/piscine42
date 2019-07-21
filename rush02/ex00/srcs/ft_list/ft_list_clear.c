/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 18:15:02 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/21 02:58:36 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)())
{
	if (!begin_list)
		return ;
	ft_list_clear(begin_list->next, free_fct);
	if (free_fct)
		free_fct(begin_list->data);
	free(begin_list);
}
