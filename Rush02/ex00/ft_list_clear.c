/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 16:26:53 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/22 16:47:07 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

void	ft_list_clear(t_list *begin_list)
{
	t_list	*tmp;

	while (begin_list != NULL)
	{
		tmp = begin_list;
		begin_list = begin_list->next;
		free(tmp);
	}
}
