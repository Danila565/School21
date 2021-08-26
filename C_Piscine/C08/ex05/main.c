/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 22:01:19 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/14 23:06:12 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "ft_stock_str.h"

struct s_stock_str *ft_strs_to_tab(int av, char **ac);

void	ft_show_tab(struct s_stock_str *par);

int main(int argc, char *argv[])
{
	(void)argc;
	t_stock_str *p;
	p = ft_strs_to_tab(argc, argv);
	ft_show_tab(p);
}
