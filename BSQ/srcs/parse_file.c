/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 18:59:38 by pmeredyt          #+#    #+#             */
/*   Updated: 2021/08/25 15:22:41 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_bool	ft_map_copy(char **str, char *file, int count)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (read(fd, *str, count) == -1)
		return (FALSE);
	(*str)[count] = '\0';
	if (close(fd) == -1)
		return (FALSE);
	return (TRUE);
}

t_bool	ft_map(char *file, char **str)
{
	char	buff[BUFFSIZE];
	int		count;
	int		d;
	int		fd;

	count = 0;
	d = 1;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (FALSE);
	while (1)
	{
		d = read(fd, buff, BUFFSIZE);
		if (d > 0)
			count += d;
		if (d == -1)
			return (FALSE);
		if (d == 0)
			break ;
	}
	*str = (char *) malloc(sizeof(char) * (count + 1));
	if (close(fd) == -1 || str == NULL)
		return (FALSE);
	return (ft_map_copy(str, file, count));
}

char	*ft_copy_first(char *str, int *i)
{
	char	*res;

	*i = 0;
	while (str[*i] != '\n' && str[*i])
		++*i;
	if (str[*i] == 0)
		return (NULL);
	res = (char *) malloc(sizeof(char) * *i);
	if (res == NULL)
		return (NULL);
	res = ft_strncpy(res, str, *i);
	res[*i] = 0;
	return (res);
}

t_errs	ft_parse_map_file(char *str, t_map *map)
{
	int		count;
	int		i;
	char	*first;

	first = ft_copy_first(str, &i);
	if (first == NULL || !ft_check_first_line(first, map))
	{
		free(first);
		free(str);
		return (FIRST_ERROR);
	}
	free(first);
	map->matrix = ft_split(str + i, "\n\0", &count);
	free(str);
	if (count != map->row)
		return (ROWS_ERROR);
	if (!ft_check_second_line(map->matrix[0], map))
		return (SECOND_ERROR);
	i = 1;
	while (++i < count)
		if (!ft_check_other_line(map->matrix[i], map))
			return (OTHER_ERROR);
	return (OK);
}

void	ft_file_work(char *file, t_map *map)
{
	char	*str;
	t_errs	errors;

	if (ft_map(file, &str))
	{
		errors = ft_parse_map_file(str, map);
		if (errors == OK)
		{
			ft_change_map(map);
			ft_print_map(map);
			ft_free_map(map);
		}
		else
		{
			write(2, "map error\n", 10);
			//if (errors != FIRST_ERROR)
				//ft_free_map(map);
		}
	}
	else
		write(2, "map error\n", 10);
}
