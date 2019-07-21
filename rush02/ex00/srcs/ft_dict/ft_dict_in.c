/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_in.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 10:34:11 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/21 10:58:04 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_dict.h"

t_data	*ft_dict_in(t_list *dict, unsigned long value)
{
	t_list *l;
	t_data d;

	d.value = value;
	return ((l = ft_list_find(dict, &d, &ft_dict_cmp)) ? l->data : NULL);
}
