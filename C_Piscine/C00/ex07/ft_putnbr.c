/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:42:16 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/05 18:52:39 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ffwrite(char a[11], int counter)
{
	int		i;

	i = counter - 1;
	while (i >= 0)
	{
		write(1, &a[i], 1);
		--i;
	}
}

void	ft_putnbr(int nb)
{	
	char	dig[11];
	int		counter;

	if (nb == 0 || nb == -2147483648)
	{
		if (nb == 0)
			write (1, "0", 1);
		else
			write(1, "-2147483648", 11);
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
