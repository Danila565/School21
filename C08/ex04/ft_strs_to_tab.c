/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 21:42:38 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/14 22:52:59 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_stock_str.h"
int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		++len;
	return (len + 1);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *) malloc(sizeof(char) * ft_strlen(src));
	if (ptr == 0)
		return (0);
	while (src[i] != '\0')
	{
		ptr[i] = src[i];
		++i;
	}
	ptr[i] = '\0';
	return (ptr);
}

void	struct_init(t_stock_str *a, int size)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		a[i].size = 0;
		a[i].str = 0;
		a[i].copy = 0;
		++i;
	}
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*res;
	int			i;

	res = malloc((sizeof (t_stock_str)) * (ac + 1));
	if (res == 0)
		return (0);
	struct_init(res, ac);
	i = 0;
	while (i < ac)
	{
		res[i].str = av[i];
		if (!res[i].str)
			return (0);
		res[i].copy = ft_strdup(av[i]);
		if (!res[i].copy)
			return (0);
		res[i].size = ft_strlen(av[i]) - 1;
		++i;
	}
	res[i].str = 0;
	return (res);
}
