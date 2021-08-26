/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 19:29:21 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/20 23:26:24 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
		int (*cmpf)(void *, void *))
{
	t_btree	*tmp;
	t_btree	*prev;

	if (*root == (void *)(0))
	{
		*root = btree_create_node(item);
		return ;
	}
	tmp = *root;
	while (tmp != (void *)(0))
	{
		prev = tmp;
		if ((*cmpf)(tmp->item, item) > 0)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}
	if ((*cmpf)(prev->item, item) > 0)
		prev->left = btree_create_node(item);
	else
		prev->right = btree_create_node(item);
}
