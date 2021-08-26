#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_btree.h"
void	func(void *data)
{
	printf("-%s-", (char *)data);
}

t_btree    *btree_create_node(void *item)
{
    t_btree    *new;

    new = malloc(sizeof (t_btree));
    if (new == (void *)(0))
        return ((void *)(0));
    new->item = item;
    new->left = 0;
    new->right = 0;
	return (new);
}

void	btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (root == (void *)(0))
		return ;
	btree_apply_suffix(root->left, applyf);
	btree_apply_suffix(root->right, applyf);
	(*applyf)(root->item);
}

int	f_strcmp(void *a, void *b)
{
	return strcmp((char *) a, (char *) b);
}

void btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *));

int main()
{
	t_btree	*tree;
	tree = (void *)(0);
	btree_insert_data(&tree, "6", &f_strcmp);
	btree_insert_data(&tree, "1", &f_strcmp);
	btree_insert_data(&tree, "8", &f_strcmp);
	btree_insert_data(&tree, "4", &f_strcmp);
	btree_insert_data(&tree, "6", &f_strcmp);
	btree_insert_data(&tree, "7", &f_strcmp);
	btree_insert_data(&tree, "0", &f_strcmp);
	btree_insert_data(&tree, "2", &f_strcmp);
	btree_insert_data(&tree, "3", &f_strcmp);
	btree_apply_suffix(tree, &func);
}
