/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 04:23:59 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/22 01:41:59 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_list.h"

void	ft_list_print(t_list *l)
{
	if (!l)
	{
		printf("NULL\n");
		return ;
	}
	printf("%s -> ", (char *)l->data);
	ft_list_print(l->next);
}

t_list	*ft_list_create(void)
{
	t_list *l;

	l = NULL;
	ft_list_push_back(&l, "a");
	ft_list_push_back(&l, "b");
	ft_list_push_back(&l, "c");
	return (l);
}

int		main(int argc, char **argv)
{
	t_list *l;
	t_list *e;

	l = ft_list_push_strs(argc - 1, argv + 1);
	printf("content: ");
	ft_list_print(l);
	printf("size: %d\n", ft_list_size(l));
	e = ft_list_at(l, 1);
	printf("2nd element: ");
	if (e)
		printf("%s\n", e->data);
	else
		printf("NULL\n");
	ft_list_reverse_fun(l);
	printf("reverse content: ");
	ft_list_print(l);
	ft_list_sort(&l, &strcmp);
	printf("sorted content: ");
	ft_list_print(l);
	ft_list_remove_if(&l, "foo", &strcmp, NULL);
	printf("removing foo: ");
	ft_list_print(l);
	ft_sorted_list_insert(&l, "foo", &strcmp);
	printf("inserting foo: ");
	ft_list_print(l);
	ft_sorted_list_merge(&l, ft_list_create(), &strcmp);
	printf("merging a b c: ");
	ft_list_print(l);
	ft_list_clear(l, NULL);
	return (0);
}
