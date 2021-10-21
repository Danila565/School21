/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 01:40:07 by efelicit          #+#    #+#             */
/*   Updated: 2021/10/11 01:40:07 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_num(char a)
{
	return (a >= '0' && a <= '9');
}

int	ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int	res;

	res = 0;
	i = 0;
	minus = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		++i;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			minus *= -1;
	}
	while (is_num(str[i]))
	{
		res *= 10;
		res += str[i] - '0';
		++i;
	}
	return (minus * res);
}
