/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 18:47:15 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/21 03:25:33 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct		s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

t_list				*ft_create_elem(void *data);

void				ft_sorted_list_insert(t_list **begin_list, void *data,
					int (*cmp)());

t_list				*ft_list_find(t_list *begin_list, void *data_ref,
					int (*cmp)());

void				ft_list_clear(t_list *begin_list, void (*free_fct)());

#endif
