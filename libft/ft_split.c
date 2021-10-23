/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 04:06:35 by efelicit          #+#    #+#             */
/*   Updated: 2021/10/22 18:32:15 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlcpy(char *dest, char *src, size_t n);

static size_t	count_num(char const *s, char c)
{
	size_t	n;
	size_t	i;

	n = 1;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			++i;
		while (s[i] != c && s[i])
		{
			if (s[i + 1] == c || s[i + 1] == '\0')
				++n;
			++i;
		}
	}
	return (n);
}

static int	ft_freeelem(char **res, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		free(res[i++]);
	free(res);
	return (0);
}

static int	myallocator(char **res, char const *s, char c)
{
	size_t	n;
	size_t	i;
	size_t	size;

	i = 0;
	n = 0;
	while (s[i])
	{
		size = 0;
		while (s[i] == c && s[i])
			++i;
		while (s[i + size] != c && s[i + size])
			++size;
		if (size)
		{
			res[n] = (char *) malloc(sizeof(char) * (size + 1));
			if (!res[n])
				return (ft_freeelem(res, n));
			ft_strlcpy(res[n++], (char *) &s[i], size + 1);
			i += size;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	n;
	char	**res;

	if (!s)
		return (NULL);
	n = count_num(s, c);
	res = (char **) malloc (sizeof(char *) * n);
	if (!(res && myallocator(res, s, c)))
		return (NULL);
	res[n - 1] = NULL;
	return (res);
}
