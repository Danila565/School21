/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 20:42:24 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/19 13:58:11 by efelicit         ###   ########.fr       */
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

t_list	*ft_list_last(t_list *begin);

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *new_elem;
	
	new_elem = ft_create_elem(data);
	new_elem->next = *begin_list;
	*begin_list = new_elem;
}
int main()
{
	t_list *res = NULL;
	ft_list_push_front(&res, "EOF.");
	ft_list_push_front(&res, "World!");
	ft_list_push_front(&res, "Hello ");
	ft_list_push_front(&res, "First elem. ");
	printf("last = %s", ft_list_last(res)->data);
}
