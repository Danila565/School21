/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 23:50:43 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/08 18:31:41 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);

char	sym(int i, int j, int x, int y)
{
	if ((i == 1 && j == 1) || (i == x && j == y))
		return ('o');
	else if ((i == 1 && j == y) || (i == x && j == 1))
		return ('o');
	else if ((i == 1 || i == x) && (j > 1 && j < y))
		return ('|');
	else if ((j == 1 || j == y) && (i > 1 && i < x))
		return ('-');
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
