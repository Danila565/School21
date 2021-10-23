/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:27:26 by efelicit          #+#    #+#             */
/*   Updated: 2021/10/22 20:47:14 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	find_endl(char *str, int d)
{
	int	i;

	i = 0;
	while(i < d)
	{
		if (str[i] == '\n' || str[i] == '\0')
			return (i);
	}
	return (-1);
}

size_t	ft_read(char **str, int fd)
{
	char *buf;
	int d;
	size_t	size;
	size_t	i;

	d = 1;
	i = 0;
	buf = (char *) malloc(sizeof(char) * BUFFSIZE);
	while(d > 0)
	{
		d = read(fd, buf, BUFFSIZE);
		if (d > 0)
		{
			++i;
			ft_strlcat(str[fd], buf, d + 1);
			size = find_endl(buf, d);
			if (size)
				break ;
		}
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	**str[MAX_FD][MAX_LEN + 1];
	char		*res;
	size_t		len;

	ft_read(str, fd);
