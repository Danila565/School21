/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 21:06:56 by pmeredyt          #+#    #+#             */
/*   Updated: 2021/08/25 12:51:11 by pmeredyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_check_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != 0)
	{
		if (charset[i] == c)
			return (1);
		++i;
	}
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != 0)
	{
		j = 0;
		while (str[i] && !ft_check_charset(str[i], charset))
		{
			++j;
			++i;
		}
		if (j > 0)
			++count;
		while (str[i] && ft_check_charset(str[i], charset))
			++i;
	}
	return (count);
}

void	ft_allocator1(char *str, char **temp, int i, int j)
{
	int	j1;

	j1 = 0;
	while (j1 < j)
	{
		(*temp)[j1] = str[i - j + j1];
		++j1;
	}
	(*temp)[j1] = 0;
}

void	ft_allocator(char **result, char *str, char *charset)
{
	int		i;
	int		j;
	int		m;
	char	*temp;

	i = 0;
	m = 0;
	while (str[i] != 0)
	{
		j = 0;
		while (str[i] && !ft_check_charset(str[i], charset))
		{
			++j;
			++i;
		}
		if (j > 0)
		{
			temp = (char *) malloc(sizeof(char) * (j + 1));
			ft_allocator1(str, &temp, i, j);
			result[m++] = temp;
		}
		while (str[i] && ft_check_charset(str[i], charset))
			++i;
	}
}

char	**ft_split(char *str, char *charset, int *count)
{
	int		k;
	char	**result;

	k = ft_count_words(str, charset);
	*count = k;
	result = (char **) malloc(sizeof(char *) * k);
	if (result == NULL)
		return (NULL);
	if (k == 0)
	{
		result[0] = NULL;
		return (result);
	}
	ft_allocator(result, str, charset);
	return (result);
}
