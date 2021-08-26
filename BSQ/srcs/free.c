/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 15:09:29 by pmeredyt          #+#    #+#             */
/*   Updated: 2021/08/24 21:50:31 by pmeredyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_free_arr(int **arr, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		free(arr[i]);
		++i;
	}
	free(arr);
}

void	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->row)
	{
		free(map->matrix[i]);
		++i;
	}
	free(map->matrix);
}
