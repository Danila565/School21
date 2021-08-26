/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 18:53:16 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/18 21:02:44 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int	is_num(char a)
{
	return (a >= '0' && a <= '9');
}

int	ft_atoi(char *str)
{
	int			i;
	int			minus;
	long long	res;

	res = 0;
	i = 0;
	minus = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		++i;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		++i;
	}
	while (str[i] != '\0' && is_num(str[i]))
	{
		res *= 10;
		res += str[i] - '0';
		++i;
	}
	return (minus * res);
}

void	ffwrite(char a[20], int counter)
{
	int		i;

	i = counter - 1;
	while (i >= 0)
	{
		write(1, &a[i], 1);
		--i;
	}
	write(1, "\n", 1);
}

void	ft_putnbr(long long nb)
{	
	char	dig[20];
	int		counter;

	if (nb == 0 || nb == -2147483648)
	{
		if (nb == 0)
			write (1, "0\n", 2);
		else
			write(1, "-2147483648\n", 12);
		return ;
	}
	counter = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	while (nb != 0)
	{			
		dig[counter++] = '0' + (nb % 10);
		nb /= 10;
	}
	ffwrite(dig, counter);
}
