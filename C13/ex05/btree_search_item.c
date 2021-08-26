/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 20:29:22 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/20 23:26:31 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_btree.h"
void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	void	*find;

	find = (void *)(0);
	if (root == (void *)(0))
		return ((void *)(0));
	find = (t_btree *) btree_search_item(root->left, data_ref, cmpf);
	if (find)
		return (find);
	if (!(*cmpf)(root->item, data_ref))
		return (root->item);
	return ((t_btree *) btree_search_item(root->right, data_ref, cmpf));
}
