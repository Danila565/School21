/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 22:39:09 by efelicit          #+#    #+#             */
/*   Updated: 2021/10/18 22:39:09 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	int	count_size(long long n)
{
	int			size;
	long long	i;

	i = n;
	size = 0;
	while (i)
	{
		++size;
		i /= 10;
	}
	size += (n <= 0);
	return (size);
}

char	*ft_itoa(int n)
{
	long long	tmp;
	char		*res;
	int			i;
	int			size;

	tmp = n;
	size = count_size(n);
	res = (char *) malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	i = 0;
	if (tmp < 0)
	{
		res[i++] = '-';
		tmp *= -1;
	}
	res[size--] = '\0';
	while (size >= i)
	{
		res[size--] = (tmp % 10) + '0';
		tmp /= 10;
	}
	return (res);
}
