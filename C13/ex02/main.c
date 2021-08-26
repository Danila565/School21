#include <stdio.h>
#include <stdlib.h>
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


void	btree_apply_infix(t_btree *tree, void (*applyf)(void *));

int main()
{
	t_btree	*tree;
	tree = (void *)(0);
	btree_apply_infix(tree, &func);
	tree = btree_create_node("root");
	tree->right = btree_create_node("right");
	tree->left = btree_create_node("left");
	tree->right->right = btree_create_node("rightright");
	tree->right->left = btree_create_node("rightleft");
	tree->left->left = btree_create_node("leftleft");
	btree_apply_infix(tree, &func);
}
