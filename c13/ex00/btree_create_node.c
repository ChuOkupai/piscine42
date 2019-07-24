/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 06:57:41 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/20 07:22:15 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree *b;

	if ((b = malloc(sizeof(t_btree))))
	{
		b->left = NULL;
		b->right = NULL;
		b->item = item;
	}
	return (b);
}
