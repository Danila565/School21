/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 23:43:28 by efelicit          #+#    #+#             */
/*   Updated: 2021/10/21 15:14:35 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char *s, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	char		num[11];
	int			i;
	long long	tmp;

	tmp = n;
	if (tmp == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (tmp < 0)
	{
		write(fd, "-", 1);
		tmp *= -1;
	}
	i = 10;
	num[i--] = '\0';
	while (tmp != 0)
	{
		num[i--] = tmp % 10 + '0';
		tmp /= 10;
	}
	ft_putstr_fd(num + i + 1, fd);
}
