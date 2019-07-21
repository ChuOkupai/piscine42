/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_create_elem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 00:56:44 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/21 22:40:02 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"
#include "ft_dict.h"

int		ft_dict_wordlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\n')
		if (ft_isspace(s[i++]))
			while (ft_isspace(s[i]))
				s++;
	return (i);
}

t_data	*ft_dict_create_elem(unsigned long value, char *name)
{
	t_data	*d;
	int		i;

	i = ft_dict_wordlen(name);
	if (!i || !(d = malloc(sizeof(t_data))))
		return (NULL);
	d->value = value;
	if (!(d->name = malloc((i + 1) * sizeof(char))))
	{
		free(d);
		return (NULL);
	}
	i = 0;
	while (*name != '\n')
	{
		d->name[i++] = (ft_isspace(*name)) ? ' ' : *name++;
		while (ft_isspace(*name) && *name != '\n')
			name++;
	}
	d->name[i] = '\0';
	return (d);
}
