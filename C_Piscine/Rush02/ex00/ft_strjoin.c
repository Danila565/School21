/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:57:00 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/22 19:27:12 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (dest[size] != '\0')
		++size;
	while (src[i] != '\0')
	{
		dest[size + i] = src[i];
		++i;
	}
	dest[size + i] = '\0';
	return (dest);
}

int	ft_strlen(char *str);

int	ft_arr_strlen(int size, char **strs)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < size)
		count += ft_strlen(strs[i++]);
	return (count);
}

char	*ft_bigcat(char *res, char **strs, int size, char *sep)
{
	int	i;
	int	tmp;

	tmp = 0;
	i = 0;
	while (i < size + size - 1)
	{
		if (i % 2 == 0)
			ft_strcat(res, strs[tmp++]);
		else
			ft_strcat(res, sep);
		++i;
	}
	return (res);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		i;
	int		count;
	int		size1;

	i = 0;
	count = 0;
	size1 = ft_strlen(sep);
	if (size < 0)
		return (0);
	if (size == 0)
	{
		res = malloc (sizeof (char));
		*res = '\0';
		return (res);
	}
	count = ft_arr_strlen(size, strs) + ((size - 1) * size1);
	res = (char *) malloc((sizeof (char)) * (count + 1));
	if (res == 0)
		return (0);
	res[0] = '\0';
	res = ft_bigcat(res, strs, size, sep);
	return (res);
}
