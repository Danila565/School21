/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:05:53 by pmeredyt          #+#    #+#             */
/*   Updated: 2021/08/25 15:25:59 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_bool	ft_check_one_char(char c, t_map *map)
{
	if (c == map->obstacle || c == map->empty)
		return (TRUE);
	return (FALSE);
}

t_bool	ft_check_other_line(char *str, t_map *map)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_check_one_char(str[i], map))
			return (FALSE);
		++i;
	}
	if (i != map->col)
		return (FALSE);
	return (TRUE);
}

t_bool	ft_check_second_line(char *str, t_map *map)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (FALSE);
	while (str[i])
	{
		if (!ft_check_one_char(str[i], map))
			return (FALSE);
		++i;
	}
	map->col = i;
	return (TRUE);
}

t_bool	ft_check_three_chars(char empty, char obstacle, char full, t_map *map)
{
	if (!(empty >= 32 && empty <= 125))
		return (FALSE);
	if (!(obstacle >= 32 && obstacle <= 126))
		return (FALSE);
	if (!(full >= 32 && full <= 126))
		return (FALSE);
	if (empty == obstacle)
		return (FALSE);
	if (obstacle == full)
		return (FALSE);
	if (full == obstacle)
		return (FALSE);
	map->obstacle = obstacle;
	map->full = full;
	map->empty = empty;
	return (TRUE);
}

t_bool	ft_check_first_line(char *str, t_map *map)
{
	int			i;
	int			size;
	long long	res;

	i = 0;
	res = 0;
	size = ft_strlen(str);
	if (size < 4)
		return (FALSE);
	if (str[0] == '0')
		return (FALSE);
	while (ft_is_digit(str[i]) && i < size - 3)
	{
		res = res * 10 + str[i] - '0';
		if (res > MAX_INT)
			return (FALSE);
		++i;
	}
	if (i != size - 3)
		return (FALSE);
	if (!ft_check_three_chars(str[size - 3], str[size - 2], str[size - 1], map))
		return (FALSE);
	map->row = res;
	return (TRUE);
}
