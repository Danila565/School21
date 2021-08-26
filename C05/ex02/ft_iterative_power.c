/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:33:30 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/11 22:07:21 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_iterative_power(int nb, int power)
{
	int	tmp;

	tmp = nb;	
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power-- > 1)
		nb *= tmp;
	return (nb);
}
