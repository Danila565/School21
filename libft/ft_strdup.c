/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 14:47:09 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/13 23:27:20 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

size_t			ft_strlen(const char *c);

char	*ft_strdup(const char *src)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *) malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (ptr == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		ptr[i] = src[i];
		++i;
	}
	ptr[i] = '\0';
	return (ptr);
}
