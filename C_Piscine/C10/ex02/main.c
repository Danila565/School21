/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: efelicit <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/08/16 15:17:16 by efelicit		  #+#	#+#			 */
/*   Updated: 2021/08/17 23:38:28 by efelicit         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/errno.h>
#include <libgen.h>
#include <stdlib.h>
char	*g_progname;
int		g_flag = 0;

int		ft_atoi(char *str);

void	ft_puterr(char *str);

void	write_stdout(char *buf, int n);

int		in_while(char *buf, int n, int *j);

void	write_err(char *name, char *str)
{
	ft_puterr(basename(name));
	write(2, ": ", 2);
	ft_puterr(str);
	write(2, ": ", 2);
	ft_puterr(strerror(errno));
	g_flag = 1;
}

int	in_file(int fd, char *buf, int n, int *j)
{
	int	d;
	int	count;

	*j = 0;
	d = n;
	count = 0;
	while (d == n)
	{
		d = read(fd, buf + (*j), n - (*j));
		if (d == n - (*j))
			*j = 0;
		else if (d > 0)
			*j += d;
		++count;
	}
	return (count);
}

void	write_name(char *name);

void	write_file(int ff, char *str, char *buf, int n)
{
	int		fd;
	int		i;
	int		count;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		write_err(g_progname, str);
	else
	{
		if (ff > 1)
			write_name(str);
		count = in_file(fd, buf, n, &i);
		if (i <= n)
		{
			if (count > 1)
				write(1, buf + i, n - i);
			write(1, buf, i);
		}
		if (close(fd) < 0)
			write_err(g_progname, str);
	}
}

void	in_main(int *i, char **argv, int *n)
{
	*i = 1;
	g_progname = argv[0];
	if (argv[1][2] == '\0')
	{
		*n = ft_atoi(argv[++(*i)]);
		++(*i);
	}
	else
		*n = ft_atoi(argv[(*i)++] + 2);
}

int	main(int argc, char **argv)
{
	int		i;
	int		n;
	char	*buf;
	int		ff;

	in_main(&i, argv, &n);
	if (n == 0)
		return (0);
	buf = malloc(sizeof (char) * n);
	if (buf == NULL)
		return (1);
	if (i == argc)
		write_stdout(buf, n);
	ff = argc - i;
	while (i < argc)
	{
		write_file(ff, argv[i], buf, n);
		if (i++ != argc - 1)
			write(1, "\n", 1);
	}
	free(buf);
	return (g_flag);
}
