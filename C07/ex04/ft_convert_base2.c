/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 23:10:28 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/13 23:24:11 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putarr(char **ptr, int i, int minus, char *n);

void	ft_put_char(char *a, int size, char **res);

void	ft_rev_char_tab(char *tab, int size)
{
	int		i;
	char	tmp;

	i = 0;
	tmp = 0;
	while (i < (size / 2))
	{
		tmp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = tmp;
		++i;
	}
}

int	arr_info(char *str)
{
	int	size;

	size = 0;
	while (str[size] != '\0')
	{
		if (str[size] == '-' || str[size] == '+')
			return (0);
		++size;
	}
	return (size);
}

int	is_valid(char *str, int size)
{
	int	j;

	if (size <= 1)
		return (0);
	while (size > 0)
	{
		if (str[size - 1] <= ' ' || str[size - 1] > '~')
			return (0);
		j = size - 2;
		while (j >= 0)
		{
			if (str[size - 1] == str[j])
				return (0);
			else
				--j;
		}
		--size;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base, char **ptr)
{
	int			size;
	int			i;
	int			minus;
	char		n[32];
	long long	tmp;

	tmp = nbr;
	i = 0;
	size = arr_info(base);
	minus = 0;
	if (tmp < 0)
	{
		minus = 1;
		tmp *= -1;
	}
	while (tmp > 0)
	{
		n[i++] = base[tmp % size];
		tmp /= size;
	}
	if (i == 0)
		n[i++] = '0';
	ft_putarr(ptr, i, minus, n);
}
