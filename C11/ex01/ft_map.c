/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:29:59 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/19 13:21:55 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	i;
	int	*res;

	res = (int *) malloc(sizeof (int) * length);
	i = 0;
	while (i < length)
	{
		res[i] = (*f)(tab[i]);
		++i;
	}
	return (res);
}
