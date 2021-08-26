/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 18:56:08 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/18 18:56:11 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_arrlen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
		++i;
	return (i);
}

void	ft_sort_string_tab(char **tab)
{
	int		n;
	int		i;
	char	*tmp;
	int		size;

	size = ft_arrlen(tab);
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
