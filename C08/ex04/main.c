/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 22:01:19 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/14 22:53:51 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "ft_stock_str.h"

struct s_stock_str *ft_strs_to_tab(int av, char **ac);

int main(int argc, char *argv[])
{
	(void)argc;
	t_stock_str *p;
	p = ft_strs_to_tab(argc, argv);
	int i = 0;
	while (p[i].str != '\0')
	{
		printf("i = %d, str = %s, copy = %s, size = %d\n", i, p[i].str, p[i].copy, p[i].size);
		++i;
	}
}
