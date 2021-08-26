/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:27:11 by pmeredyt          #+#    #+#             */
/*   Updated: 2021/08/19 19:36:37 by pmeredyt         ###   ########.fr       */
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

int	cmp(int a, int b)
{
	if (a == b)
		return (0);
	return (1);
}

void	free_fct(void *data)
{
	(void) data;
	printf("Free data\n");
}

int	main(void)
{
	t_list	*node;
	int		first;
	int		second;
	int		third;
	t_list	*last;

	first = 1;
	second = 2;
	third = 3;
	node = NULL;
	ft_list_push_back(&node, &first);
	ft_list_push_back(&node, &second);
	ft_list_push_back(&node, &first);
	ft_list_push_back(&node, &second);
	ft_list_push_back(&node, &third);
	ft_list_push_back(&node, &second);
	ft_list_push_back(&node, &second);
	ft_list_push_back(&node, &second);
	ft_list_push_back(&node, &second);
	ft_list_push_back(&node, &second);
	ft_list_push_back(&node, &second);
	ft_list_push_back(&node, &second);
	ft_list_push_back(&node, &second);
	ft_list_push_back(&node, &second);
	ft_print_list(node);
	ft_list_remove_if(&node, &second, cmp, free_fct);
	ft_print_list(node);
	return (0);
}
