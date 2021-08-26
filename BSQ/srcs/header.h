/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 17:06:53 by pmeredyt          #+#    #+#             */
/*   Updated: 2021/08/25 14:51:37 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# define BUFFSIZE 5
# define MAX_INT 2147483647

typedef struct s_map
{
	char	**matrix;
	int		col;
	int		row;
	char	full;
	char	obstacle;
	char	empty;
}	t_map;

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef enum e_errs
{
	FIRST_ERROR,
	ROWS_ERROR,
	SECOND_ERROR,
	OTHER_ERROR,
	OK
}	t_errs;

/*---------------------dp.c---------------------*/
int		*ft_dp(t_map *map);
void	ft_check_max(int arr[3], int i, int j, int curr);
int		**ft_init(int row, int col, t_map *map, int arr[3]);
int		ft_min(int a, int b, int c);

/*-----------------change_map.c-----------------*/
void	ft_print_map(t_map *map);
void	ft_change_map(t_map *map);

/*-----------------check_map.c------------------*/
t_bool	ft_check_one_char(char c, t_map *map);
t_bool	ft_check_other_line(char *str, t_map *map);
t_bool	ft_check_second_line(char *str, t_map *map);
t_bool	ft_check_first_line(char *str, t_map *map);
t_bool	ft_check_three_chars(char empty, char obstacle, char full, t_map *map);

/*-------------------split.c--------------------*/
void	ft_allocator(char **result, char *str, char *charset);
void	ft_allocator1(char *str, char **temp, int i, int j);
int		ft_count_words(char *str, char *charset);
int		ft_check_charset(char c, char *charset);
char	**ft_split(char *str, char *charset, int *count);

/*-----------------parse_file.c-----------------*/
t_errs	ft_parse_map_file(char *str, t_map *map);
t_bool	ft_map_copy(char **str, char *file, int count);
t_bool	ft_map(char *file, char **str);
char	*ft_copy_first(char *str, int *i);
void	ft_file_work(char *file, t_map *map);

/*-----------------parse_stdin.c----------------*/
char	*ft_realloc(char *buf, int *k);
char	*ft_read_line(int size);
t_bool	ft_parse_map_stdin(t_map *map);

/*--------------------free.c--------------------*/
void	ft_free_arr(int **arr, int row);
void	ft_free_map(t_map *map);

/*--------------------string.c--------------------*/
char	*ft_strncpy(char *dest, char *src, int n);
int		ft_strlen(char *str);
t_bool	ft_is_digit(char c);

#endif
