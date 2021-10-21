/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:52:51 by efelicit          #+#    #+#             */
/*   Updated: 2021/10/20 20:11:49 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*beg;
	t_list	*new;

	if (!lst)
		return (NULL);
	beg = ft_lstnew((*f)(lst->content));
	if (!beg)
		return (NULL);
	new = beg;
	lst = lst->next;
	while (lst)
	{
		new->next = ft_lstnew((*f)(lst->content));
		if (!new->next)
		{
			ft_lstclear(&beg, del);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (beg);
}
