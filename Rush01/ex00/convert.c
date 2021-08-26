/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 18:54:28 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/15 20:48:23 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		++count;
	return (count);
}


int	ft_is_digit(char c)
{
	return (c >= '1' && c <= '4');
}

int ft_is_space(char c)
{
	return (c == ' ');
}

int	convert(char *str, int a[2][8])
{
	int	b;
	int	i;
	int	count;

	count = 0;
	i = 0;
	b = ft_strlen(str);
	if (b != 31)
		return (0);
	while (i < 31)
	{
		if (!ft_is_digit(str[i]))
			return (0);
		a[count / 8][count % 8] = str[i] - '0';
		++count;
		++i;
		if (!ft_is_space(str[i]) && i != 31)
			return (0);
		++i;
	}
	return (1);
}



