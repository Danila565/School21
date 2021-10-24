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
#include "get_next_line.h"
#include <stdio.h>
size_t	ft_read(char *str[MAX_FD], int fd)
{
	char 	*buf;
	int 	d;
	char	*tmp;

	d = 1;
	if (!str[fd])
		str[fd] = ft_strjoin("", "", 0);
	buf = (char *) malloc(sizeof(char) * BUFFSIZE);
	while (d > 0)
	{
		d = read(fd, buf, BUFFSIZE);
		if (d > 0)
		{
			tmp = str[fd];
			str[fd] = ft_strjoin(str[fd], buf, d);
			free(tmp);
		}
		if (ft_strchr(buf, '\n') || d < BUFFSIZE)
			break ;
	}
	free(buf);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*str[MAX_FD];
	static int	i = 0;
	char		*line;
	size_t		len;
	char		*tmp;

	ft_read(str, fd);

	line = ft_strchr(str[fd], '\n');
	if (!line)
	{
		len = ft_strlen(str[fd]);
		if (len == 0)
			return (NULL);
	}
	else
		len = line - str[fd];
	line = ft_substr(str[fd], 0, len + 1);
	tmp = ft_substr(str[fd], len + 1, ft_strlen(str[fd] + len + 1));
	free(str[fd]);
	str[fd] = tmp;
	++i;
	return (line);
}
