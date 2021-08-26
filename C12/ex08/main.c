/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 20:42:24 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/19 17:38:25 by efelicit         ###   ########.fr       */
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

void	ft_list_reverse(t_list **begin_listr);
int main()
{
	t_list *res = NULL;
	t_list *begin = NULL;
	ft_list_push_front(&res, "4World!");
	ft_list_push_front(&res, "3Hello ");
	ft_list_push_front(&res, "2text. ");
	ft_list_push_front(&res, "1Something ");
	ft_list_push_front(&res, "0First elem. ");
	begin = res;
	while(res != NULL)
	{
		printf("%s",(char *) res->data);
		res = res->next;
	}
	ft_list_reverse(&begin);
	res = begin;
	printf("\n");
	while(res != NULL)
	{
		printf("%s",(char *) res->data);
		res = res->next;
	}
}
