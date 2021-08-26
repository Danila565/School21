/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sight.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efelicit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 18:39:50 by efelicit          #+#    #+#             */
/*   Updated: 2021/08/15 20:14:28 by efelicit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	row_while(int arr[4][4], int seen[2], int i)
{
	int	j;
	int	max[2];

	j = 0;
	max[0] = 5;
	max[1] = 0;
	seen[0] = 0;
	seen[1] = 0;
	while (j < 4)
	{
		if (arr[i][j] > max[1])
		{
			max[1] = arr[i][j];
			max[0] = arr[i][j];
			seen[0]++;
			seen[1] = 1;
		}
		else if (arr[i][j] < max[0])
		{
			max[0] = arr[i][j];
			seen[1]++;
		}
		++j;
	}
}

int	check_row(int arr[4][4], int a[2][8])
{
	int	i;
	//int	max[2];
	int	seen[2];

	i = 0;
	while (i < 4)
	{
		row_while(arr, seen, i);
		if (seen[0] != a[1][i] || seen[1] != a[1][i + 4])
			return (0);
		++i;
	}
	return (1);
}

void	col_while(int arr[4][4], int seen[2], int i)
{
	int	j;
	int	max[2];

	j = 0;
	//max[0] = 5;
	max[1] = 0;
	seen[0] = 0;
	seen[1] = 0;
	while (j < 4)
	{
		if (arr[j][i] > max[1])
		{
			max[1] = arr[j][i];
			max[0] = arr[j][i];
			seen[0]++;
			seen[1] = 1;
		}
		else if (arr[j][i] < max[0])
		{
			max[0] = arr[j][i];
			seen[1]++;
		}
		++j;
	}
}

int	check_col(int arr[4][4], int a[2][8])
{
	int	i;
	int	seen[2];

	i = 0;
	while (i < 4)
	{
		col_while(arr, seen, i);
		if (seen[0] != a[0][i] || seen[1] != a[0][i + 4])
			return (0);
		++i;
	}
	return (1);
}

int	check_skyscraper(int arr[4][4], int a[2][8])
{
	if (check_row(arr, a)
			&& check_col(arr, a))
		return (1);
	return (0);
}


/*int main(int argc, char **argv)
{
	int	x;
	int	map[4][4] = {{1, 2, 3, 4}, {2, 3, 4, 1}, {3, 4, 1, 2}, {4, 1, 2, 3}};
	int	inputs[2][8];

	while(1
	x = check_skyscraper(map, inputs);
	printf("\n");
	printf(" %d ", );
	printf(" %d ", );
	return (0);
}*/

