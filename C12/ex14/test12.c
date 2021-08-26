/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:27:11 by pmeredyt          #+#    #+#             */
/*   Updated: 2021/08/20 11:55:37 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));

t_list	*ft_create_elem(void *data)
{
	t_list	*node;

	node = (t_list *) malloc(sizeof(t_list));
	node->data = data;
	node->next = NULL;
	return (node);
}

void	ft_print_list(t_list *head)
{
	int i = 0;
	if (head == NULL)
		printf("NULL!");
	while (head != NULL)
	{
		printf("%d ", *((int *)head->data));
		head = head->next;
	}
	printf("\n");
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*temp;

	
	if (*begin_list == NULL)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	temp = *begin_list;
	*begin_list = ft_create_elem(data);
	(*begin_list)->next = temp;
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*it;

	if (*begin_list == NULL)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	it = *begin_list;
	while (it->next != NULL)
		it = it->next;
	it->next = ft_create_elem(data);
}

int	cmp(int *a, int *b)
{
	return (*a - *b);
}

void	free_fct(void *data)
{
	(void) data;
	printf("Free data\n");
}

void	ft_list_sort(t_list **begin_list, int (*cmp)());

int	main(void)
{
	t_list	*node;
	t_list	*res = NULL;
	int		x1;
	int		x2;
	int		x3, x4,x5,x6;
	t_list	*last;

	x1 = 1;
	x2 = 2;
	x3 = 3;
	x4 = 4;
	x5 = 5;
	x6 = 6;
	node = NULL;
	ft_list_push_back(&node, &x6);
	ft_list_push_back(&node, &x5);
	ft_list_push_back(&node, &x4);
	ft_list_push_back(&node, &x3);
	ft_list_push_back(&node, &x2);
	ft_list_push_back(&node, &x1);
	ft_list_push_back(&node, &x3);
	ft_list_push_back(&node, &x3);
	/*ft_list_push_back(&node, &second);
	ft_list_push_back(&node, &second);
	ft_list_push_back(&node, &second);
	ft_list_push_back(&node, &second);
	ft_list_push_back(&node, &second);
	ft_list_push_back(&node, &second);*/
	ft_print_list(node);
	ft_list_sort(&res, cmp);
	ft_print_list(node);
	return (0);
}
