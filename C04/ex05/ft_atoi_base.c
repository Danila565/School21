/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 21:07:23 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/10 22:52:15 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int	arr_info(char *str)
{
	int	size;

	size = 0;
	while (str[size] != '\0')
	{
		if (str[size] == '-' || str[size] == '+')
			return (0);
		++size;
	}
	return (size);
}

int	is_valid(char *str, int size)
{
	int	j;

	if (size <= 1)
		return (0);
	while (size > 0)
	{
		if (str[size - 1] <= ' ' || str[size - 1] > '~')
			return (0);
		j = size - 2;
		while (j >= 0)
		{
			if (str[size - 1] == str[j])
				return (0);
			else
				--j;
		}
		--size;
	}
	return (1);
}

int	is_num(char a, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (a == base[i])
			return (i);
		++i;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	minus;
	int	res;
	int	size;

	size = arr_info(base);
	if (!is_valid(base, size))
		return (0);
	res = 0;
	i = 0;
	minus = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		++i;
	while (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			minus *= -1;
	while (str[i] != '\0' && is_num(str[i], base) >= 0)
	{
		res *= size;
		res += is_num(str[i++], base);
	}
	return (minus * res);
}
