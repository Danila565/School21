/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 17:18:50 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/11 17:09:56 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_sqrt(int nb)
{
	long long	tmp;
	long long	l;
	long long	r;

	if (nb < 0)
		return (0);
	if (nb == 1)
		return (1);
	l = 1;
	r = nb;
	tmp = nb / 2;
	while (l != r)
	{
		if (tmp * tmp > nb)
			r = tmp;
		if (tmp * tmp < nb)
			l = tmp;
		tmp = (l + r) / 2;
		if (tmp * tmp == nb)
			return (tmp);
		if (tmp == 1 || tmp == l || tmp == r)
			return (0);
	}
	return (0);
}
