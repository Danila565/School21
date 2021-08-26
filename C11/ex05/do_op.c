/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 20:13:45 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/18 21:04:04 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
long long	plus(long long a, long long b);

long long	minus(long long a, long long b);

long long	multi(long long a, long long b);

long long	div(long long a, long long b);

long long	mod(long long a, long long b);

long long	ft_atoi(char *str);

void		ft_putnbr(long long nbr);

int	bad_op(char *a)
{
	if (!(a[0] == '+' || a[0] == '-' || a[0] == '*'
			|| a[0] == '/' || a[0] == '%'))
		return (1);
	if (a[1] != '\0')
		return (1);
	return (0);
}

void	do_op(char **argv, long long (*ptr[5])(long long, long long))
{
	int	a;
	int	b;

	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	if (argv[2][0] == '+')
		ft_putnbr((*ptr[0])(a, b));
	if (argv[2][0] == '-')
		ft_putnbr((*ptr[1])(a, b));
	if (argv[2][0] == '*')
		ft_putnbr((*ptr[2])(a, b));
	if (argv[2][0] == '/')
	{
		if (b == 0)
			write(1, "Stop: divizion by zero\n", 23);
		else
			ft_putnbr((*ptr[3])(a, b));
	}
	if (argv[2][0] == '%')
	{
		if (b == 0)
			write(1, "Stop: modulo by zero\n", 21);
		else
			ft_putnbr((*ptr[4])(a, b));
	}
}

int	main(int argc, char **argv)
{
	long	long	(*ptr[5])(long long, long long);

	if (argc != 4)
		return (0);
	if (bad_op(argv[2]))
	{
		write(1, "0\n", 2);
	}
	else
	{
		ptr[0] = plus;
		ptr[1] = minus;
		ptr[2] = multi;
		ptr[3] = div;
		ptr[4] = mod;
		do_op(argv, ptr);
	}
}
