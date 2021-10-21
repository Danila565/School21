/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 04:14:06 by efelicit          #+#    #+#             */
/*   Updated: 2021/10/21 15:49:43 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (dest);
	while (n != 0)
	{
		--n;
		((char *) dest)[n] = ((char *) src)[n];
	}
	return (dest);
}
