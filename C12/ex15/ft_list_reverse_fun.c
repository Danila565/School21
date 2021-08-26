/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 22:04:53 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/19 22:42:22 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

int	ft_list_size(t_list *begin_list, t_list **mid)
{
	t_list	*curr;
	int		i;

	i = 0;
	curr = begin_list;
	*mid = begin_list;
	while (curr != 0)
	{
		curr = curr->next;
		++i;
		if (i % 2 == 0)
			*mid = (*mid)->next;
	}
	return (i);
}

void	ft_swap_data(t_list *a, t_list *b)
{
	void	*tmp;

	tmp = a->data;
	a->data = b->data;
	b->data = tmp;
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*i;
	t_list	*j;
	int		ind[2];
	t_list	*mid;
	int		size;

	size = ft_list_size(begin_list, &mid);
	ind[0] = 0;
	i = begin_list;
	while (ind[0] < (size / 2))
	{
		ind[1] = (size / 2) + 1;
		j = mid;
		while (ind[1] < size - ind[0])
		{
			j = j->next;
			ind[1]++;
		}
		ft_swap_data(i, j);
		i = i->next;
		++ind[0];
	}
}
