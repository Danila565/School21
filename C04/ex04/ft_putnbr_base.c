/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:28:36 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/13 10:59:28 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

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
		if (str[size - 1] < ' ' || str[size - 1] > '~')
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

void	ft_put_revstr(char *a, int size)
{
	while (size >= 0)
	{
		write(1, a + size, 1);
		--size;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			size;
	int			i;
	char		n[32];
	long long	tmp;

	tmp = nbr;
	i = 0;
	size = arr_info(base);
	if (!is_valid(base, size))
		return ;
	if (tmp == 0)
		write(1, base, 1);
	if (tmp < 0)
	{
		write(1, "-", 1);
		tmp *= -1;
	}
	while (tmp > 0)
	{
		n[i++] = base[tmp % size];
		tmp /= size;
	}
	ft_put_revstr(n, i - 1);
}
