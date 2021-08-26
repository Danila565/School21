/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 20:10:35 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/07 23:14:38 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
char	int_to_char(int a)
{
	if (a >= 0 && a <= 9)
		return (a + '0');
	else
		return ((a % 10) + 'a');
}

int	is_print(char a)
{
	if (a >= 32 && a <= 126)
		return (1);
	else
		return (0);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	tmp[3];

	tmp[0] = '\\';
	tmp[1] = '0';
	tmp[2] = '0';
	i = 0;
	while (str[i] != '\0')
	{
		if (is_print(str[i]))
			write(1, str + i, 1);
		else
		{
			tmp[1] = int_to_char(str[i] / 16);
			tmp[2] = int_to_char(str[i] % 16);
			write(1, tmp, 3);
		}
		++i;
	}
}
