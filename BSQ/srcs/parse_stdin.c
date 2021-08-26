/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stdin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 19:25:27 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/25 15:21:00 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

char	*ft_realloc(char *buf, int *k)
{
	char	*tmp;

	tmp = (char *) malloc(sizeof (char) * ((*k * 3) / 2));
	tmp = ft_strncpy(tmp, buf, *k + 1);
	*k = (*k * 3) / 2;
	//printf("TMP = %s\n", tmp);
	free(buf);
	return (tmp);
}

char	*ft_read_line(int size)
{
	char	*buf;
	int		k;
	int		i;
	int		d;

	k = size;
	i = 0;
	d = k;
	buf = (char *) malloc(sizeof (char) * k);
	while (TRUE)
	{
		d = read(0, buf + i, k - i);
		if (d < 0)
			return (NULL);
		else if (buf[i + d - 1] == '\n' || d == 0)
			break;
		else if (d == k - i)
		{
			//printf("OK\n");
			buf = ft_realloc(buf, &k);
			i += d;
		}
	}
	//printf("buf1 = %s\n", buf);
	buf[i + d - 1] = '\0';
	//printf("buf2 = %s\n", buf);
	return (buf);
}

t_bool	ft_parse_map_stdin(t_map *map)
{
	char	*buf;
	int		j;

	j = 0;
	buf = ft_read_line(20);
	//printf("%s\n", buf);
	if (buf == NULL || !ft_check_first_line(buf, map))
	{
		free(buf);
		return (FALSE);
	}
	free(buf);
	//printf("AFTER FIRST CHECK\n");
	//printf("MAP: %d %c %c %c\n", map->row, map->empty, map->obstacle, map->full);
	map->matrix = (char **) malloc (sizeof (char *) * map->row);
	buf = ft_read_line(BUFFSIZE);
	if (buf == NULL || !ft_check_second_line(buf, map))
	{
		free(buf);
		printf("ERROR :)\n");
		return (FALSE);
	}
	map->matrix[j++] = buf;
	printf("Second line = -%s-\n", map->matrix[0]);
	//printf("MAP: %d %d\n", map->row, map->col);
	while (j < map->row)
	{
		map->matrix[j] = ft_read_line(map->col + 1);
		//printf("%d line = %s\n", j, map->matrix[j]);
		if (!ft_check_other_line(map->matrix[j], map))
			return (FALSE);
		++j;
	}
	return (TRUE);
}
