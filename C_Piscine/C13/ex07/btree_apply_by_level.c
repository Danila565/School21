/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   btree_apply_by_level.c							 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: efelicit <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/08/20 22:20:39 by efelicit		  #+#	#+#			 */
/*   Updated: 2021/08/20 23:26:51 by efelicit         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */
#include "ft_btree.h"
#include <stdlib.h>
int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	btree_level_count(t_btree *root)
{
	if (root == (void *)(0))
		return (0);
	return (1 + max(btree_level_count(root->left),
			btree_level_count(root->right)));
}

void	init_arr(t_btree **arr, int size, int ind[2])
{
	int	i;

	ind[0] = 0;
	ind[1] = 0;
	i = 0;
	while (i < size)
	{
		arr[i] = NULL;
		++i;
	}
}

void	ft_copy(t_btree **prev, t_btree **new, int *i, int *j)
{
	if (prev[*i]->left != NULL)
		new[(*j)++] = prev[*i]->left;
	if (prev[*i]->right != NULL)
		new[(*j)++] = prev[*i]->left;
	(*i)++;
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
			int current_level, int is_first_elem))
{
	t_btree	**prev;
	t_btree	**new;
	int		level[2];
	int		ind[2];

	if (root == (void *)(0))
		return ;
	level[0] = 0;
	prev = (t_btree **) malloc(sizeof (t_btree *) * (++level[0]) * 2);
	applyf(root->item, 0, 1);
	init_arr(prev, 2, ind);
	level[1] = btree_level_count(root);
	ft_copy(&root, prev, ind, ind + 1);
	while (level[0] < level[1])
	{
		new = (t_btree **) malloc(sizeof (t_btree *) * (++level[0]) * 2);
		init_arr(new, level[0] * 2, ind);
		while (prev[ind[0]] != NULL)
		{
			applyf(prev[ind[0]]->item, level[0], (ind[0] == 0));
			ft_copy(prev, new, ind, ind + 1);
		}
		free(prev);
		prev = new;
	}
}
