/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 20:42:24 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/19 18:27:51 by efelicit         ###   ########.fr       */
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

void	func(void *a)
{
	printf("I'm here!\n");
}

void	ft_list_foreach(t_list *begin_listr, void (*f)(void *));
int main()
{
	void	(*p)(void *);
	p = func;
	t_list *res = NULL;
	t_list *begin = NULL;
	int first = 1;
	int second = 2;
	ft_list_push_front(&res, &first);
	ft_list_push_front(&res, &second);
	//ft_list_push_front(&res, "2text. ");
	//ft_list_push_front(&res, "1Something ");
	//ft_list_push_front(&res, "0First elem. ");
	begin = res;
	while(res != NULL)
	{
		printf("%d\n",*((int *) res->data));
		res = res->next;
	}
	ft_list_foreach(begin, func);
	res = begin;
	while(res != NULL)
	{
		printf("%d\n",*((int *) res->data));
		res = res->next;
	}
}
