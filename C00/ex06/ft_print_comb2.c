/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 20:10:42 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/05 21:47:17 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ffwrite(char a[])
{	
	write(1, a, 5);
	if (! (a[0] == '9' && a[1] == '8'))
		write(1, ", ", 2);
}

void	arr_init(char a[])
{
	a[0] = '0';
	a[1] = '0';
	a[2] = ' ';
	a[3] = '0';
	a[4] = '1';
}

void	ft_print_comb2(void)
{
	char	arr[6];

	arr_init(arr);
	while (arr[0] <= '9')
	{
		arr[1] = '0';
		while (arr[1] <= '9')
		{
			arr[3] = arr[0];
			arr[4] = arr[1] + 1;
			while (arr[3] <= '9')
			{
				while (arr[4] <= '9')
				{
					ffwrite(arr);
					++arr[4];
				}
				++arr[3];
				arr[4] = '0';
			}
			++arr[1];
		}
		++arr[0];
	}
}
