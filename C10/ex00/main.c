/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:17:16 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/17 23:35:40 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <unistd.h>
int	main(int argc, char **argv)
{
	int		fd;
	char	buf;

	if (argc != 2)
	{
		if (argc < 2)
			write(1, "File name is missing.\n", 22);
		if (argc > 2)
			write(1, "Too many arguments.\n", 20);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "Cannot read file.\n", 18);
		return (0);
	}
	while (read(fd, &buf, 1))
		write(1, &buf, 1);
	close(fd);
	return (0);
}
