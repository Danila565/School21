/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 14:12:24 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/19 23:40:20 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data);

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new_elem;

	new_elem = ft_create_elem(data);
	new_elem->next = *begin_list;
	*begin_list = new_elem;
}

t_list	*ft_list_push_strs(int size, char **str)
{
	t_list	*curr;
	int		i;

	if (size == 0)
		return (NULL);
	i = 0;
	curr = NULL;
	while (i < size)
		ft_list_push_front(&curr, str[i++]);
	return (curr);
}
