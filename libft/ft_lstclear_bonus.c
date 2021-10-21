/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstclear_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:35:52 by efelicit          #+#    #+#             */
/*   Updated: 2021/10/20 20:11:18 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*prev;

	while (*lst)
	{
		prev = *lst;
		*lst = (*lst)->next;
		(*del)(prev->content);
		free(prev);
	}
}
