/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 14:47:09 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/22 19:31:00 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		++len;
	return (len);
}

void	ft_putstr(char *s1)
{
	int	i;

	i = ft_strlen(s1);
	write(1, s1, i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *) malloc(sizeof(char) * ft_strlen(src));
	if (ptr == 0)
		return (0);
	while (src[i] != '\0')
	{
		ptr[i] = src[i];
		++i;
	}
	ptr[i] = '\0';
	return (ptr);
}
