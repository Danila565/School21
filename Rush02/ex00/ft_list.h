/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 20:31:44 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/22 19:33:04 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_LIST_H
# define FT_LIST_H
# include <stdlib.h>
typedef struct s_list
{
	struct s_list	*next;
	char			*data;
}	t_list;

void	ft_list_clear(t_list *begin_list);
t_list	*ft_create_elem(char *data);
void	ft_list_push_back(t_list **begin_list, char *data);
#endif
