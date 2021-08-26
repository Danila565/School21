/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:47:38 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/19 20:26:09 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
	  	int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*prev;
	t_list	*curr;
	t_list	*next;

	prev = NULL;
	curr = *begin_list;
	while (curr != NULL)
	{
		next = curr->next;
		if (!(*cmp)(curr->data, data_ref))
		{
			(*free_fct)(curr->data);
			if (prev == NULL)
				*begin_list = (*begin_list)->next;
			else
				prev->next = curr->next;
			free(curr);
		}
		else
			prev = curr;
		curr = next;
	}
}
