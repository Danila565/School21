/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 20:38:33 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/19 13:30:31 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"
t_list	*ft_create_elem(void *data)
{
	t_list	*res;

	res = malloc(sizeof (t_list));
	if (res == NULL)
		res = NULL;
	res->data = data;
	res->next = NULL;
	return (res);
}
