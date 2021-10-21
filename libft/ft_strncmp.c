/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 01:42:00 by efelicit          #+#    #+#             */
/*   Updated: 2021/10/21 16:05:45 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i != n)
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		++i;
	}
	return (0);
}
#include <string.h>
#include <stdio.h>
int main()
{
	printf("%d\n", strncmp("test\200", "test\0", 10));
	printf("%d\n", ft_strncmp("test\200", "test\0", 10));
}
