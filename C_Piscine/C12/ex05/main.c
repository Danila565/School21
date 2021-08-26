/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 20:42:24 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/19 14:22:43 by efelicit         ###   ########.fr       */
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

void    ft_list_push_back(t_list **begin_list, void *data)
{
    t_list *new_elem;
    
    if (*begin_list == NULL)
    {
        *begin_list = ft_create_elem(data);
        return ;
    }
    new_elem = *begin_list;
    while (new_elem->next != NULL)
        new_elem = new_elem->next;
    new_elem->next = ft_create_elem(data);
}

t_list	*ft_list_push_strs(int size, char **strs);

int main(int argc, char **argv)
{
	t_list *res;
	res = ft_list_push_strs(argc, argv);
	while(res != NULL)
	{
		printf("%s\n",(char *) res->data);
		res = res->next;
	}
}
