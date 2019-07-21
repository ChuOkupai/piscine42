/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 00:10:08 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/21 10:57:35 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DICT_H
# define FT_DICT_H

# include "ft_list.h"

typedef struct		s_data
{
	unsigned long	value;
	char			*name;
}					t_data;

t_list				*ft_dict_create(char *content);

t_data				*ft_dict_create_elem(unsigned long value, char *name);

t_data				*ft_dict_in(t_list *dict, unsigned long value);

int					ft_dict_cmp(t_data *d1, t_data *d2);

void				ft_dict_clear(t_data *d);

void				ft_print(t_list *dict, char *value);

#endif
