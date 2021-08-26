/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 16:46:10 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/19 23:14:03 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list	*curr;

	curr = begin_list;
	if (begin_list == NULL)
		return (NULL);
	while (nbr != 0)
	{
		if (curr == NULL)
			return (NULL);
		curr = curr->next;
		--nbr;
	}
	return (curr);
}
