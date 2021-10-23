/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 01:42:00 by efelicit          #+#    #+#             */
/*   Updated: 2021/10/21 16:36:57 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*d1;
	const unsigned char	*d2;

	i = 0;
	d1 = (const unsigned char *) s1;
	d2 = (const unsigned char *) s2;
	while (i != n)
	{
		if (d1[i] == '\0' && d2[i] == '\0')
			return (0);
		if (d1[i] != d2[i])
			return (d1[i] - d2[i]);
		++i;
	}
	return (0);
}
