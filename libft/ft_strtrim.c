/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 03:42:16 by efelicit          #+#    #+#             */
/*   Updated: 2021/10/20 21:53:41 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *c);

int		ft_strlcpy(char *dest, char *src, size_t n);

static int	ft_isset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		++i;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	while (ft_isset(s1[i], set) && s1[i])
	{
		++i;
	}
	j = ft_strlen(s1);
	if (j != 0)
	{
		--j;
		while (ft_isset(s1[j], set) && j > i)
		{
			--j;
		}
		++j;
	}
	res = (char *) malloc(sizeof(char) * (j - i + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, (char *) &s1[i], j - i + 1);
	return (res);
}
