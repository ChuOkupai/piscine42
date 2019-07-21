/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 00:48:04 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/21 23:26:38 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"
#include "ft_dict.h"

t_list	*ft_dicterr(t_list *l)
{
	ft_list_clear(l, &ft_dict_clear);
	ft_putstr("Dict Error\n");
	return (NULL);
}

int		ft_is_valid_line(char *s, unsigned long *value, char **name)
{
	long	n;
	int		i;

	i = 0;
	while (ft_isdigit(s[i]))
		i++;
	if (!i || i > 18 || (n = ft_atol(s)) < 0)
		return (0);
	*value = n;
	s += i;
	while (ft_isspace(*s))
		s++;
	if (*s++ != ':')
		return (0);
	while (ft_isspace(*s))
		s++;
	*name = s;
	i = 0;
	while (s[i] && s[i] != '\n')
		if (!ft_isprint(s[i]))
			return (0);
		else if (ft_isspace(s[i++]))
			while (ft_isspace(s[i]))
				s++;
	return (i && s[i] == '\n');
}

t_list	*ft_dict_check(t_list *dict)
{
	unsigned int i;

	i = -1;
	while (++i < 10)
		if (!ft_dict_in(dict, i) || !ft_dict_in(dict, 10 + i)
			|| !ft_dict_in(dict, 10 * i))
			return (ft_dicterr(dict));
	if (!ft_dict_in(dict, 100) || !ft_dict_in(dict, 1000)
		|| !ft_dict_in(dict, 1000000) || !ft_dict_in(dict, 1000000))
		return (ft_dicterr(dict));
	return (dict);
}

t_list	*ft_dict_create(char *content)
{
	t_list *l;
	t_data *e;
	t_data t;

	l = NULL;
	while (*content)
	{
		if (*content == '\n')
			content++;
		else if (ft_is_valid_line(content, &t.value, &t.name)
			&& !ft_list_find(l, &t, ft_dict_cmp)
			&& (e = ft_dict_create_elem(t.value, t.name)))
		{
			ft_sorted_list_insert(&l, e, &ft_dict_cmp);
			while (*content != '\n')
				content++;
		}
		else
			return (ft_dicterr(l));
	}
	return (ft_dict_check(l));
}
