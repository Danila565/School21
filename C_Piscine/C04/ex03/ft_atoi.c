/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:44:15 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/10 22:42:34 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	is_num(char a)
{
	return (a >= '0' && a <= '9');
}

int	ft_atoi(char *str)
{
	int	i;
	int	minus;
	int	res;

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
