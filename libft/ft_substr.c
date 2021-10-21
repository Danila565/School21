/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 02:59:07 by efelicit          #+#    #+#             */
/*   Updated: 2021/10/20 21:41:43 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlcpy(char *dest, char *src, size_t n);

size_t	ft_strlen(const char *c);

static size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*res;

	size = ft_strlen(s);
	if (size < start + 1)
		len = 0;
	len = ft_min(len + 1, size - start + 1);
	res = (char *) malloc(sizeof(char) * len);
	if (!res)
		return (NULL);
	ft_strlcpy(res, (char *) &s[start], len);
	return (res);
}
