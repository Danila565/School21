/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 19:27:31 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/15 20:26:50 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	board(char perm[25][5], char *a, int count, int *total);
void	perm_town(int tmp[4], int count, int a[2][8]);
void proverka(int tmp[4]);
int	check_all(int tmp[4], int a[2][8]);
int	ftabs(int x1)
{
	if (x1 < 0)
		x1 *= -1;
	return (x1);
}

int	g_flag;

void	ffwrite(int a[4])
{
	char	tmp;
	int		i;

	i = 0;
	while (i < 4)
	{
		tmp = '0' + a[i++];
		write(1, &tmp, 1);
	}
	write(1, "\n", 1);
}

void	in_while(char perm[25][5],int count, int i, char *a, int *total)
{
	int	j;

	j = 0;
	//printf("in while\n");
	while (j < count)
	{
			//printf("3");
		if ((i + '0') == a[j])
			break ;
		++j;
	}
	if (j == count)
		board(perm, a, count + 1, total);
}

/*void	arr_permu(int **a, int count)
{
	int	i;

	i = 0;
	if (count == 0)
	{
		while (i < 4)
		{
			a[count] = ++i;
		}
	}
}*/

char	*ft_strcpy(char *dest, char *src)
{
	int	sz_s;

	sz_s = 0;
	while (src[sz_s] != '\0')
	{
		dest[sz_s] = src[sz_s];
		++sz_s;
	}
	dest[sz_s] = src[sz_s];
	return (dest);
}

void	board(char perm[25][5], char *a, int count, int *total)
{
	int	i;

	i = 1;
	if (count == 0)
	{
		while (i < 5)
		{
			//printf("2");
			a[count] = '0' + i;
			board(perm, a, count + 1, total);
			++i;
		}
	}
	else if (count < 4)
	{
		i = 1;
		while (i < 5)
		{
			//printf("1");
			a[count] = '0' + i;
			in_while(perm, count, i++, a, total);
		}
	}
	if (count == 4)
	{
		ft_strcpy(perm[*total], a);
		(*total)++;
		//write(1, a, 4);
		//write(1, "\n", 1);
	}
}

void	print_line(char perm[25][5])
{
	int	i;

	i = 0;
	while(perm[i][0] != 0)
	{
		write(1, perm[i], 4);
		write(1, "\n", 1);
		++i;
	}
}

void	in_town(int tmp[4], int count, int i, int a[2][8])
{
	int	j;

	j = 0;
	if (g_flag)
		return ;
	//printf("in while\n");
	while (j < count)
	{
			//printf("3");
		if (i == tmp[j])
			break ;
		++j;
	}
	if (j == count)
		perm_town(tmp, count + 1, a);
}


void	perm_town(int tmp[4], int count, int a[2][8])
{
	int i = 0;
	if (count == 0)
	{
		while (i < 24)
		{
			//printf("2");
			tmp[count] = i;
			perm_town(tmp, count + 1, a);
			if (g_flag)
				return ;
			++i;
		}
	}
	else if (count < 4)
	{
		i = 0;
		while (i < 24)
		{
			//printf("1");
			tmp[count] = i;
			in_town(tmp, count, i++, a);
			if(g_flag)
				return ;
		}
	}
	if (count == 4)
	{
		//ft_strcpy(perm[*total], a);
		//(*total)++;
		write(1, "3k\n", 3);
		if(check_all(tmp, a))
		{
			g_flag = 1;
		}
		write(1, "4k\n", 3);
		//write(1, a, 4);
		//write(1, "\n", 1);
	}
}

int	rush(int a[2][8])
{
	//char	town[4][4];
	int		tmp[4];
	char	perm[25][5];
	char	queens[5];
	int	total;
	total = 0;
	perm[24][0] = '\0';
	queens[4] = '\0';
	//board(perm, queens, 0, &total);
	printf("1k\n");
	//print_line(perm);
	total = 0;
	g_flag = 0;
	//perm_town(tmp, 0, a);
	printf("2k\n");
	total = g_flag;
	return (total);
}
