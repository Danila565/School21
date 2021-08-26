/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_atoi.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: efelicit <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/08/09 15:44:15 by efelicit		  #+#	#+#			 */
/*   Updated: 2021/08/17 23:33:06 by efelicit         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/errno.h>
#include <libgen.h>
#include <stdlib.h>

int	in_while(char *buf, int n, int *j)
{
	int		d;
	char	prev;
	int		d_prev;
	int		count;

	*j = 0;
	d_prev = -1;
	d = 1;
	count = 0;
	while (d >= 0)
	{
		d = read(0, buf + (*j), n - (*j));
		if (d == n - (*j))
			*j = 0;
		else if (d > 0)
			*j += d;
		if (d == 0 && d_prev == -1)
			break ;
		if (d == 0 && (prev == '\n' || d_prev < n))
			break ;
		prev = buf[d - 1];
		++count;
		d_prev = d;
	}
	return (count);
}

long long	ft_atoi(char *str)
{
	int			i;
	int			minus;
	long long	res;

	res = 0;
	i = 0;
	minus = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		++i;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		res *= 10;
		res += str[i] - '0';
		++i;
	}
	return (minus * res);
}

void	write_name(char *name)
{
	int	i;

	i = 0;
	write(1, "==> ", 4);
	while (name[i] != '\0')
		write(1, name + i++, 1);
	write(1, " <==\n", 5);
}

void	ft_puterr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(2, str + i, 1);
		++i;
	}
}

void	write_stdout(char *buf, int n)
{
	int	i;
	int	count;

	count = in_while(buf, n, &i);
	if (count > 1)
		write(1, buf + i, n - i);
	write(1, buf, i);
}
