/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 01:58:50 by efelicit          #+#    #+#             */
/*   Updated: 2021/10/07 01:58:50 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	if (n == 0)
		return (0);
	p1 = (unsigned char *) s1;
	p2 = (unsigned char *) s2;
	while (n != 0)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		++p1;
		++p2;
		--n;
	}
	return (0);
}
