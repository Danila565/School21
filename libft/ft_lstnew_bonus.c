/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:45:47 by efelicit          #+#    #+#             */
/*   Updated: 2021/10/20 20:10:47 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newel;

	newel = (t_list *) malloc(sizeof(t_list));
	if (!newel)
		return (NULL);
	newel->content = content;
	newel->next = NULL;
	return (newel);
}
