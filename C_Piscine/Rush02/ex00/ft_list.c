/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_create_elem.c								   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: efelicit <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/08/18 20:38:33 by efelicit		  #+#	#+#			 */
/*   Updated: 2021/08/22 19:46:10 by efelicit         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */
#include "ft_list.h"
t_list	*ft_create_elem(char *data)
{
	t_list	*res;

	res = malloc(sizeof (t_list));
	if (res == NULL)
		res = NULL;
	res->data = data;
	res->next = NULL;
	return (res);
}

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

void	ft_list_push_back(t_list **begin_list, char *data)
{
	t_list	*new_elem;

	if (*begin_list == NULL)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	new_elem = *begin_list;
	while (new_elem->next != NULL)
		new_elem = new_elem->next;
	new_elem->next = ft_create_elem(data);
}
