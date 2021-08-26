/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 00:56:10 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/08 16:06:25 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

char	sym(int i, int j, int x, int y)
{
	if ((i == 1 && j == 1) || (i == 1 && j == y))
		return ('A');
	else if ((i == x && j == y) || (i == x && j == 1))
		return ('C');
	else if ((i == 1 || i == x) && (j > 1 && j < y))
		return ('B');
	else if ((j == 1 || j == y) && (i > 1 && i < x))
		return ('B');
	return (' ');
}

void	rush(int x, int y)
{
	int		i;
	int		j;
	char	tmp;

	i = 1;
	j = 1;
	while (j <= y)
	{
		i = 1;
		while (i <= x)
		{
			tmp = sym(i, j, x, y);
			write(1, &tmp, 1);
			++i;
		}
		write(1, "\n", 1);
		++j;
	}
}
