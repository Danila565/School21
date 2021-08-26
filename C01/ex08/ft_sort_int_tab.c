/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 21:52:42 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/06 23:22:26 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_sort_int_tab(int *tab, int size)
{
	int		n;
	int		i;
	int		tmp;

	n = 0;
	while (n <= size - 2)
	{
		i = size - 1;
		while (i != n)
		{
			if (tab[i] < tab[i - 1])
			{
				tmp = tab[i];
				tab[i] = tab[i - 1];
				tab[i - 1] = tmp;
			}
			--i;
		}
		++n;
	}
}
