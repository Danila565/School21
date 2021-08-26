/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 18:34:05 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/25 12:44:45 by pmeredyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

void	ft_change_map(t_map *map)
{
	int	*dp;
	int	i;
	int	j;

	dp = ft_dp(map);
	if (dp[2] == 0)
	{
		free(dp);
		return ;
	}
	i = dp[0] - dp[2] + 1;
	while (i <= dp[0])
	{
		j = dp[1] - dp[2] + 1;
		while (j <= dp[1])
		{
			map->matrix[i][j] = map->full;
			++j;
		}
		++i;
	}
	free(dp);
}

void	ft_print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->row)
	{
		write(1, map->matrix[i], map->col);
		write(1, "\n", 1);
		++i;
	}
}
