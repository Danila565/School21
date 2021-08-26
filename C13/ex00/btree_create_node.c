/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:56:54 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/20 23:24:08 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_btree.h"
#include <stdlib.h>
t_btree	*btree_create_node(void *item)
{
	t_btree	*new;

	new = malloc(sizeof (t_btree));
	if (new == (void *)(0))
		return ((void *)(0));
	new->item = item;
	new->left = NULL;
	new->right = NULL;
	return (new);
}
