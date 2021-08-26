/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 19:28:01 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/19 19:55:29 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*curr;

	if (*begin_list1 == NULL)
		*begin_list1 = begin_list2;
	else
	{
		curr = *begin_list1;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = begin_list2;
	}
}
