/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:48:37 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/11 20:03:56 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr(char *a)
{
	int	i;

	i = 0;
	while (a[i] != '\0')
	{
		write(1, a + i, 1);
		++i;
	}
	write(1, "\n", 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s1[i] == '\0')
		return (s1[i] - s2[i]);
	while (s1[i] != '\0')
	{
		if (s2[i] == '\0')
			return (s1[i]);
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		++i;
	}
	return (s1[i] - s2[i]);
}

void	ft_sort_str_tab(char **tab, int size)
{
	int		n;
	int		i;
	char	*tmp;

	n = 0;
	while (n <= size - 2)
	{
		i = size - 1;
		while (i != n)
		{
			if (ft_strcmp(tab[i], tab[i - 1]) < 0)
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

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	ft_sort_str_tab(argv, argc);
	while (i < argc)
		ft_putstr(argv[i++]);
	return (0);
}	
