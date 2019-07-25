/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 07:44:38 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/25 06:26:54 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	void *item;

	if (!root)
		return (NULL);
	if ((item = btree_search_item(root->left, data_ref, cmpf)))
		return (item);
	if (!cmpf(data_ref, root->item))
		return (root->item);
	return (btree_search_item(root->right, data_ref, cmpf));
}
