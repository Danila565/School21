/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 12:33:46 by pmeredyt          #+#    #+#             */
/*   Updated: 2021/08/25 14:35:45 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strncpy(char *dest, char *src, int n)
{
	int		i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	while (i < n)
	{
		dest[i] = '\0';
		++i;
	}
	return (dest);
}

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		++count;
	return (count);
}

t_bool	ft_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}
