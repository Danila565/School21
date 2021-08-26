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
void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	t_btree *tmp;
	t_btree *prev;

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
	char *c = (char *) a;
	char *d = (char *) b;
	return  c[0] - d[0];
	//return strcmp((char *) a, (char *) b);
}

void btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *));
void *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *));
int main()
{
	t_btree	*tree;
	tree = (void *)(0);
	btree_insert_data(&tree, "6-6", &f_strcmp);
	btree_insert_data(&tree, "1-5", &f_strcmp);
	btree_insert_data(&tree, "8-9", &f_strcmp);
	btree_insert_data(&tree, "31-4", &f_strcmp);
	btree_insert_data(&tree, "62-8", &f_strcmp);
	btree_insert_data(&tree, "7-7", &f_strcmp);
	btree_insert_data(&tree, "0-1", &f_strcmp);
	btree_insert_data(&tree, "2-2", &f_strcmp);
	btree_insert_data(&tree, "32-3", &f_strcmp);
	//btree_apply_suffix(tree, &func);
	tree = NULL;
	char *res = (char *)  btree_search_item(tree, "-99", &f_strcmp);
	if (res == NULL)
		printf("%p\n", res);
	else
		printf("%s\n", res);

}
