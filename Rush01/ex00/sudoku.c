/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 18:34:16 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/15 20:17:38 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
void	board(char perm[25][5], char *a, int count, int *total);
char	*ft_strcpy(char *dest, char *src);
int		check_skyscraper(char arr[4][5], int a[2][8]);
int	sud_row(char arr[4][5])
{
	int i, j, k;
	i = 0;
	j = 0;
	k = 0;
	while(i < 4)
	{
        j = 0;
        while(j < 4)
        {
                k = j + 1;
                while(k <  4)
                {
                        if(arr[i][j] == arr[i][k])
                                return 0;
                        ++k;
                }
                ++j;
        }
        ++i;
	}
	return (1);
}

int	sud_col(char arr[4][5])
{
	int i, j, k;
	i = 0;
	j = 0;
	k = 0;
	while(i < 4)
	{
        j = 0;
        while(j < 4)
        {
                k = j + 1;
                while(k <  4)
                {
                        if(arr[j][i] == arr[k][i])
                                return 0;
                        ++k;
                }
                ++j;
        }
        ++i;
	}
	return (1);
}


int     check_sudoku(char arr[4][5])
{
	if(sud_row(arr) && sud_col(arr))
		return 1;
	return (0);
}

void	print_town(char arr[4][5])
{
	int		i;
	int 	j;
	char	tmp;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			tmp = arr[i][j];
			write(1, &tmp, 1);
				if (j != 3)
					write(1, " ", 1);
			++j;
		}
		write(1, "\n", 1);
		++i;
	}
}

int	check_all(int tmp[4], int  a[2][8])
{
	char	perm[25][5];
	char	queens[5];
	char	arr[4][5];
	int	total;
	int	i;

	i = 0;
	total = 0;
	perm[24][0] = '\0';
	queens[4] = '\0';
	board(perm, queens, 0, &total);
	while (i < 4)
	{
		ft_strcpy(arr[i], perm[tmp[i]]);
		++i;
	}
	if (check_sudoku(arr) && check_skyscraper(arr, a))
	{
		print_town(arr);
		return (1);
	}
	return (0);
}
