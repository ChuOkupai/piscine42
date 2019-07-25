/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 06:13:56 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/25 09:42:14 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_btree.h"

void	btree_clear(t_btree *root)
{
	if (!root)
		return ;
	btree_clear(root->left);
	btree_clear(root->right);
	free(root);
}

void	btree_print(t_btree *node, unsigned int deep)
{
	unsigned int i;

	if (!node)
		return ;
	if (deep)
	{
		i = 0;
		while (++i < deep)
			printf("  ");
		printf("↳ ");
	}
	printf("%s\n", node->item);
	btree_print(node->left, deep + 1);
	btree_print(node->right, deep + 1);
}

void	btree_ultimate_print(void *item, int level, int is_first_elem)
{
	printf("[%s] l:[%d] f:[%d]\n", item, level, is_first_elem);
}

int		ft_fakestrcmp(void *s1, void *s2)
{
	return (strcmp(s1, s2));
}

int		main(int argc, char **argv)
{
	t_btree	*b;
	int		i;

	if (argc < 1)
		return (0);
	b = NULL;
	i = 1;
	while (i < argc)
		btree_insert_data(&b, argv[i++], &ft_fakestrcmp);
	btree_print(b, 0);
	btree_apply_by_level(b, &btree_ultimate_print);
	if (btree_search_item(b, "foo", &ft_fakestrcmp))
		printf("foo found!\n");
	printf("height: %d\n", btree_level_count(b));
	btree_clear(b);
	return (0);
}
