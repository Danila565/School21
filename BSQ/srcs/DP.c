/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DP.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 17:26:13 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/25 15:19:25 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

void	ft_check_max(int arr[3], int i, int j, int curr)
{
	if (curr > arr[2])
	{
		arr[2] = curr;
		arr[0] = i;
		arr[1] = j;
	}
}

int	**ft_init(int row, int col, t_map *map, int arr[3])
{
	int	**res;
	int	i;
	int	j;

	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 0;
	i = 0;
	res = (int **) malloc(sizeof (int *) * row);
	while (i < row)
		res[i++] = (int *) malloc(sizeof (int) * col);
	i = 0;
	while (i < row)
	{
		res[i][0] = (map->empty == map->matrix[i][0]);
		ft_check_max(arr, i, 0, res[i][0]);
		++i;
	}
	j = -1;
	while (++j < col)
	{
		res[0][j] = (map->empty == map->matrix[0][j]);
		ft_check_max(arr, 0, j, res[0][j]);
	}
	return (res);
}

int	ft_min(int a, int b, int c)
{
	int	min;

	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return (min);
}

int	*ft_dp(t_map *map)
{
	int	i;
	int	j;
	int	**die;
	int	*res;

	res = (int *) malloc(sizeof (int) * 3);
	die = ft_init(map->row, map->col, map, res);
	i = 0;
	while (++i < map->row)
	{
		j = 0;
		while (++j < map->col)
		{
			if (map->matrix[i][j] == map->empty)
			{
				die[i][j] = 1 + ft_min(die[i - 1][j], die[i][j - 1],
						die[i - 1][j - 1]);
				ft_check_max(res, i, j, die[i][j]);
			}
			else
				die[i][j] = 0;
		}
	}
	ft_free_arr(die, map->row);
	return (res);
}
