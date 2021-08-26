/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 17:29:59 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/22 20:15:42 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_list.h"
#define BUFFSIZE 1024

typedef struct s_str
{
	char	*value;
}	t_str;

int		ft_strlen(char *str);
char	*ft_strjoin(int size, char **strs, char *sep);
char	*ft_strdup(char *src);
int		ft_strcmp(char *s1, char *s2);
char	**ft_split(char *str, char *charset, int *count);

void	ft_putstr(char *s1);

t_str	**ft_malloc(void)
{
	t_str	**res;
	int		i;

	res = (t_str **)malloc(sizeof(t_str *) * 4);
	res[0] = (t_str *)malloc(sizeof(t_str) * 10);
	i = 0;
	while (i < 10)
		res[0][i++].value = NULL;
	res[1] = (t_str *)malloc(sizeof(t_str) * 10);
	i = 0;
	while (i < 10)
		res[1][i++].value = NULL;
	res[2] = (t_str *) malloc(sizeof(t_str) * 8);
	i = 0;
	while (i < 8)
		res[2][i++].value = NULL;
	res[3] = (t_str *) malloc(sizeof(t_str) * 13);
	i = 0;
	while (i < 13)
		res[3][i++].value = NULL;
	return (res);
}

void	free_dict(t_str **dict)
{
	int	i;
	
	i = 0;
	while (i < 10)
		free(dict[0][i++].value);
	free(dict[0]);
	i = 0;
	while (i < 10)
		free(dict[1][i++].value);
	free(dict[1]);
	i = 0;
	while (i < 8)
		free(dict[2][i++].value);
	free(dict[2]);
	i = 0;
	while (i < 13)
		free(dict[3][i++].value);
	free(dict[3]);
	free(dict);
}

int	byte_count(int fd)
{
	int		count;
	int		d;
	char	buf[BUFFSIZE];

	count = 0;
	d = 1024;
	while (d == 1024)
	{
		d = read(fd, buf, BUFFSIZE);
		if (d < 0)
		{
			write(2, "Dict Error\n", 11);
			return (0);
		}
		count += d;
	}
	return (count);
}

char	*file_work(char *name)
{
	int		fd;
	int		size;
	int		d;
	char	*str;

	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Dict Error\n", 11);
		return (NULL);
	}
	d = 0;
	size = byte_count(fd);
	str = (char *) malloc((sizeof (char)) * (size + 1));
	close(fd);
	fd = open(name, O_RDONLY);
	printf("size = %d\n", size);
	if (fd == -1)
	{
		write(2, "Dict Error\n", 11);
		return (NULL);
	}
	read(fd, str, size);
	if (close(fd) == -1)
	{
		write(2, "Dict Error\n", 11);
		return (NULL);
	}
	return (str);
}

int	only_zeros(char *num, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (num[i] != '0')
			return (0);
		else
			++i;
	}
	return (1);
}

void	add_word(char *num, char *word, t_str **dict)
{
	int	size;

	size = ft_strlen(num);
	if (size == 1)
		dict[0][num[0] - '0'].value = ft_strdup(word);
	else if (size == 2)
	{
		if (num[0] == '1')
			dict[1][num[1] - '0'].value = ft_strdup(word);
		else
			dict[2][num[0] - '2'].value = ft_strdup(word);
	}
	else if (size >= 3 && num[0] == '1')
	{
		if (!ft_strcmp(num, "100"))
			dict[3][0].value = ft_strdup(word);
		else if (size <= 37 && (size % 3 == 1) && only_zeros(num + 1, size - 1))
			dict[3][size / 3].value = ft_strdup(word);
	}
}

int	parse_map(char *name, t_str **dict)
{
	char	*str;
	char	**lines;
	char	**temp;
	int		count;
	int		size;

	str = file_work(name);
	if (str == NULL)
		return (1);
	lines = ft_split(str, "\n\0", &size);
	free(str);
	while (*lines != NULL)
	{
		temp = ft_split(*lines, " :\0", &count);
		str = ft_strjoin(count - 1, (temp + 1), " ");
		add_word(temp[0], str, dict);
		while (count > 0)
		{
			free(temp[--count]);
		}
		free(str);
		free(*lines);
		++lines;
	}
	free(lines - size);
	return (0);
}

void	print_list(t_list *word)
{
	while (word != NULL)
	{
		ft_putstr(word->data);
		if (word->next != NULL)
			write(1, " ", 1);
		word = word->next;
	}
}

void	translate(t_str **dict, char *num)
{
	int		size;
	int		i;
	t_list	*word;

	word = NULL;
	i = 0;
	size = ft_strlen(num);
	if (!ft_strcmp(num, "0"))
	{
		ft_putstr(dict[0][0].value);
		return ;
	}
	while (i < size)
	{
		if (num[i] == '0' && (size - i - 1) % 3 != 0)
			++i;
		else if ((size - i - 1) % 3 == 2)
		{
			ft_list_push_back(&word, (dict[0][num[i] - '0'].value));
			ft_list_push_back(&word, (dict[3][0]).value);
		}
		else if ((size - i - 1) % 3 == 1)
		{
			if (num[i] == '1')
			{
				ft_list_push_back(&word, (dict[1][num[++i] - '0'].value));
				ft_list_push_back(&word, (dict[3][(size - i) / 3].value));
			}
			else
				ft_list_push_back(&word, (dict[2][num[i] - '2'].value));
		}
		else if ((size - i - 1) % 3 == 0)
		{
			if (num[i] != '0')
				ft_list_push_back(&word, (dict[0][num[i] - '0'].value));
			if (i != size - 1)
				ft_list_push_back(&word, (dict[3][(size - i) / 3].value));
		}
		++i;
	}
	print_list(word);
}



int	main(int argc, char **argv)
{
	t_str	**dict;
	int		i;

	i = 1;
	dict = ft_malloc();
	if (argc < 2 || argc > 3)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	else if (argc == 2)
		parse_map("numbers.dict", dict);
	else if (argc == 3)
		parse_map(argv[i++], dict);
	translate(dict, argv[i]);
	//free_dict(dict);
	getchar();
	return (0);
}
