/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 21:35:04 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/19 22:47:00 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	t_list	*curr;
	int		i;

	i = 0;
	curr = begin_list;
	while (curr != 0)
	{
		curr = curr->next;
		++i;
	}
	return (i);
}
