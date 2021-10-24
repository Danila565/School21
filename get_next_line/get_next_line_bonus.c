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
	char *buf;
	int d;

	d = 1;
	if (!str[fd])
		str[fd] = "";
	buf = (char *) malloc(sizeof(char) * BUFFSIZE);
	while(d > 0)
	{
		d = read(fd, buf, BUFFSIZE);
		if (d > 0)
			str[fd] = ft_strjoin(str[fd], buf, d);
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

	//printf("%d - ok1\n", i);
	ft_read(str, fd);
	//printf("%d - ok2\n", i);

	line = ft_strchr(str[fd], '\n');
	if (!line)
	{
		//printf("111 - |%s|\n", str[fd]);
		len = ft_strlen(str[fd]);
		if (len == 0)
			return (NULL);
	}
	else
	{
		//printf("222 - |%s|\n", str[fd]);
		len = line - str[fd];
	}
	//printf("len = %ld - ok3\n", len);
	line = ft_substr(str[fd], 0, len + 1);
	//printf("%d - ok4\n", i);
	tmp = ft_substr(str[fd], len + 1, ft_strlen(str[fd] + len + 1));
	//printf("%d - ok5\n", i);
	free(str[fd]);
	//printf("%d - ok6\n", i);
	str[fd] = tmp;
	++i;
	return (line);
}
