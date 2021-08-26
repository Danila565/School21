/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 20:42:24 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/18 21:40:49 by efelicit         ###   ########.fr       */
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

void	ft_list_push_front(t_list **begin, void *data);

int main()
{
	t_list *res;
	res = ft_create_elem("World!");
	ft_list_push_front(&res, "Hello ");
	while(res != NULL)
	{
		printf("%s",(char *) res->data);
		res = res->next;
	}
}
			
