/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 22:18:12 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/19 19:11:22 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*curr;
	int		i;

	i = 0;
	curr = begin_list;
	if (begin_list == NULL)
		return (begin_list);
	while (curr->next != 0)
	{
		curr = curr->next;
		++i;
	}
	return (curr);
}
