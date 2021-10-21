/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 04:44:02 by efelicit          #+#    #+#             */
/*   Updated: 2021/10/06 04:44:02 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strlcpy(char *dest, char *src, size_t n)
{
	size_t	i;
	char	*s;

	if (!src)
		return (0);
	s = src;
	i = n;
	if (i != 0)
	{
		while (--i != 0)
		{
			*dest++ = *s++;
			if ((*(dest - 1)) == 0)
				break ;
		}
	}
	if (i == 0)
	{
		if (n != 0)
			*dest = '\0';
		while (*s++)
			;
	}
	return (s - src - 1);
}
