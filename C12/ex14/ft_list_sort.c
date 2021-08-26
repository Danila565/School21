/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 19:55:47 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/20 11:56:59 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"
#include <stdio.h>

void	swap(t_list **l1, t_list **l2)
{
	t_list	*tmp;

	tmp = *l1;
	*l1 = *l2;
	*l2 = tmp;
}

void	big_swap(t_list **p1, t_list **p2, t_list **fix, t_list **curr)
{
	if ((*fix)->next == *curr)
	{
		if (*p1 != NULL)
			(*p1)->next = *curr;
		(*fix)->next = (*curr)->next;
		(*curr)->next = (*fix);
	}
	else
	{
		swap(&(*fix)->next, &(*curr)->next);
		if (*p1 != NULL)
			swap(&(*p1)->next, &(*p2)->next);
		else
			(*p2)->next = *fix;
	}
	swap(fix, curr);
}

void	reinit(t_list **a, t_list **b)
{
	*b = *a;
	*a = (*a)->next;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*p1;
	t_list	*p2;
	t_list	*curr;
	t_list	*fix;

	fix = *begin_list;
	if(fix == NULL) //after check
		return ;    //after check
	p1 = NULL;
	while (fix->next != NULL)
	{
		curr = fix->next;
		p2 = fix;
		while (curr != NULL)
		{
			if ((*cmp)(fix->data, curr->data) > 0)
			{
				if (p1 == NULL)
					*begin_list = curr;
				big_swap(&p1, &p2, &fix, &curr);
			}
			reinit(&curr, &p2);
		}
		reinit(&fix, &p1);
	}
}	
