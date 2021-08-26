/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 17:13:48 by pmeredyt          #+#    #+#             */
/*   Updated: 2021/08/25 16:09:24 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <time.h>



int	main(int argc, char *argv[])
{
	t_map	map;
	int		i;
	
	i = 0;
	if (argc == 1)
	{
		if (ft_parse_map_stdin(&map))
		{
			ft_change_map(&map);
			ft_print_map(&map);
			ft_free_map(&map);
		}
		else
			write(2, "map error\n", 10);
	}	
	while (++i < argc)
	{
		time_t start, end;
		start = clock();
		ft_file_work(argv[i], &map);
		if (i != argc - 1)
			write(1, "\n", 1);
		end = clock();
		printf("%.15f\n", (double) (end - start) / CLOCKS_PER_SEC);
	}
	getchar();
	return (0);
}
