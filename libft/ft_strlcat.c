/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 23:44:22 by efelicit          #+#    #+#             */
/*   Updated: 2021/10/06 23:44:22 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

size_t	ft_strlen(const char *c);

int	ft_strlcat(char *dest, char *src, size_t n)
{
	size_t	i;
	size_t	dlen;
	char	*d;
	char	*s;

	if (!dest || !src)
		return (ft_strlen(dest) + ft_strlen(src));
	d = dest;
	s = src;
	i = n;
	while (i-- != 0 && *d != '\0')
		++d;
	dlen = d - dest;
	i = n - dlen;
	if (i == 0)
		return (dlen + ft_strlen(src));
	while (*s != '\0')
	{
		if (i != 0 && i-- > 1)
			*d++ = *s;
		++s;
	}
	*d = 0;
	return (dlen + (s - src));
}
