/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 20:42:24 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/19 19:49:37 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"
t_list    *ft_create_elem(void *data)
{
    t_list    *res;

    res = malloc(sizeof (t_list));
    res->data = data;
    res->next = NULL;
    return (res);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *new_elem;
	
	new_elem = ft_create_elem(data);
	new_elem->next = *begin_list;
	*begin_list = new_elem;
}

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2);
int main()
{
	t_list *res = NULL;
	t_list	*res1 = NULL;
	t_list	*res2 = NULL;
	ft_list_push_front(&res1, "World!");
	ft_list_push_front(&res1, "Hello ");
	ft_list_push_front(&res1, "First elem. ");
	ft_list_push_front(&res2, "Word!");
	ft_list_push_front(&res2, "Bye ");
	ft_list_push_front(&res2, "Second elem. ");
	ft_list_merge(&res1, res2);
	ft_list_merge(&res, res1);
	while(res != NULL)
	{
		printf("%s",(char *) res->data);
		res = res->next;
	}
}
