/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 16:08:00 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/12 20:56:51 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	f_name(char *a)
{
	int	i;

	i = 0;
	while (a[i] != '\0')
		write(1, a + i++, 1);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	f_name(argv[0]);
	return (0);
}
