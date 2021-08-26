/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 20:42:24 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/18 22:01:33 by efelicit         ###   ########.fr       */
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

int	ft_list_size(t_list *begin_list);

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
	printf("size = %d\n", ft_list_size(res));
	ft_list_push_front(&res, "World!");
	printf("size = %d\n", ft_list_size(res));
	ft_list_push_front(&res, "Hello ");
	printf("size = %d\n", ft_list_size(res));
	ft_list_push_front(&res, "First elem. ");
	printf("size = %d\n", ft_list_size(res));
	while(res != NULL)
	{
		printf("%s",(char *) res->data);
		res = res->next;
	}
}
