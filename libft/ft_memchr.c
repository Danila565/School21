/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 01:45:47 by efelicit          #+#    #+#             */
/*   Updated: 2021/10/07 01:45:47 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	*ft_memchr(const void *s, int a, size_t n)
{
	void			*p;
	unsigned char	c;

	p = (void *) s;
	c = (unsigned char) a;
	while (n != 0)
	{
		if (*((unsigned char *) p) == c)
			return (p);
		++p;
		--n;
	}
	return ((void *)(0));
}
