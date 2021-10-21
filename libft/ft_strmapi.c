/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmapi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 00:00:57 by efelicit          #+#    #+#             */
/*   Updated: 2021/10/19 00:00:57 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *c);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*res;
	size_t	i;

	len = ft_strlen(s);
	res = (char *) malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	i = 0;
	while (s[i])
	{
		res[i] = (*f)(i, s[i]);
		++i;
	}
	return (res);
}
