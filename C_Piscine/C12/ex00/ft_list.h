/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 20:31:44 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/19 23:25:30 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_LIST_H
# define FT_LIST_H
# include <stdlib.h>
typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;
#endif
