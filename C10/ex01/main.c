/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:17:16 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/17 20:35:27 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/errno.h>
#include <libgen.h>
#define BUFFSIZE 1024

void	ft_puterr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		write(2, str + i, 1);
		++i;
	}
}

void	write_err(char *name, char *str)
{
	ft_puterr(basename(name));
	write(2, ": ", 2);
	ft_puterr(str);
	write(2, ": ", 2);
	ft_puterr(strerror(errno));
	write(2, "\n", 1);
}

void	write_stdout(char *buf)
{
	int		d;
	char	prev;
	int		d_prev;

	d_prev = -1;
	d = 1;
	while (d >= 0)
	{
		d = read(0, buf, BUFFSIZE);
		if (d == 0 && d_prev == -1)
			break ;
		if (d == 0 && (prev == '\n' || d_prev < BUFFSIZE))
			break ;
		if (d > 0)
			write(1, buf, d);
		prev = buf[d - 1];
		d_prev = d;
	}
}

void	write_file(char *name, char *str, char *buf)
{
	int		fd;
	int		d;
	int		a;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		write_err(name, str);
	else
	{
		d = 1024;
		a = 1024;
		while (d >= BUFFSIZE && a >= BUFFSIZE)
		{
			d = read(fd, buf, BUFFSIZE);
			if (d == -1)
				write_err(name, str);
			if (d > 0)
				a = write(1, buf, d);
			if (a == -1)
				write_err(name, str);
		}
		if (close(fd) < 0)
			write_err(name, str);
	}
}

int	main(int argc, char **argv)
{
	int		i;	
	char	buf[BUFFSIZE];

	i = 1;
	if (argc == 1)
		write_stdout(buf);
	else if (argv[i][0] == '-' && argv[i][1] == '-' && argv[i][2] == '\0')
	{
		if (argc == 2)
			write_stdout(buf);
		++i;
	}
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '\0')
			write_stdout(buf);
		else
			write_file(argv[0], argv[i], buf);
		++i;
	}
	if (errno)
		return (1);
	return (0);
}
