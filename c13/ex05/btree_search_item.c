/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 07:44:38 by asoursou          #+#    #+#             */
/*   Updated: 2019/07/22 08:50:08 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	void *data;

	if (!root)
		return (NULL);
	if ((data = btree_search_item(root->left, data_ref, cmpf)))
		return (data);
	if (!cmpf(data_ref, root->item))
		return (root);
	return (btree_search_item(root->right, data_ref, cmpf));
}
