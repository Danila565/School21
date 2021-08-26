/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 10:18:50 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/13 23:26:22 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
int		arr_info(char *str);

int		is_valid(char *str, int size);

void	ft_putnbr_base(int nbr, char *base, char **ptr);

void	ft_rev_char_tab(char *a, int size);

void	ft_put_char(char *a, int size, char **res)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	ft_rev_char_tab(a, size);
	if ((*res)[0] == '-')
		++i;
	while (j <= size)
	{
		(*res)[i] = a[j];
		++i;
		++j;
	}
	(*res)[size + 1] = '\0';
}

void	ft_putarr(char **ptr, int i, int minus, char *n)
{
	*ptr = (char *) malloc((sizeof (char)) * (i + minus + 1));
	if (minus)
		(*ptr)[0] = '-';
	ft_put_char(n, i, ptr);
}

int	is_num(char a, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (a == base[i])
			return (i);
		++i;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int			i;
	int			minus;
	long long	res;
	int			size;

	size = arr_info(base);
	if (!is_valid(base, size))
		return (0);
	res = 0;
	i = 0;
	minus = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		++i;
	while (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			minus *= -1;
	while (str[i] != '\0' && is_num(str[i], base) >= 0 )
	{
		res *= size;
		res += is_num(str[i++], base);
	}
	return (minus * res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long	res;
	int			sizef;
	int			sizet;
	int			minus;
	char		*ptr;

	minus = 0;
	sizef = arr_info(base_from);
	sizet = arr_info(base_to);
	if (!is_valid(base_from, sizef) || !is_valid(base_to, sizet))
		return (0);
	res = ft_atoi_base(nbr, base_from);
	ft_putnbr_base(res, base_to, &ptr);
	return (ptr);
}
