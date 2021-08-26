/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 19:14:14 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/11 21:16:04 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	board(int a[10], int count, int *total);

int	ftabs(int x1)
{
	if (x1 < 0)
		x1 *= -1;
	return (x1);
}

void	ffwrite(int a[10])
{
	char	tmp;
	int		i;

	i = 0;
	while (i < 10)
	{
		tmp = '0' + a[i++];
		write(1, &tmp, 1);
	}
	write(1, "\n", 1);
}

void	in_while(int count, int i, int a[10], int *total)
{
	int	j;

	j = 0;
	while (j < count)
	{
		if (i == a[j])
			break ;
		if ((ftabs(j - count) == ftabs(i - a[j])))
			break ;
		++j;
	}
	if (j == count)
		board(a, count + 1, total);
}

void	board(int a[10], int count, int *total)
{
	int	i;

	i = 0;
	if (count == 0)
	{
		while (i < 10)
		{
			a[count] = i++;
			board(a, count + 1, total);
		}
	}
	else if (count < 10)
	{
		while (i < 10)
		{
			a[count] = i;
			in_while(count, i++, a, total);
		}
	}
	if (count == 10)
	{
		(*total)++;
		ffwrite(a);
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	queens[10];
	int	total;

	total = 0;
	board(queens, 0, &total);
	return (total);
}
