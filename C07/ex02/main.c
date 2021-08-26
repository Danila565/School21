#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max);

int	main(void)
{
	int *arr;
	int min, max;
	scanf("%d%d", &min, &max);
	int size = ft_ultimate_range(&arr, min, max);
	printf("size = %d\n", size);
	printf("pointer = %p\n", arr);
	for (int i = 0; i < max - min; ++i)
			printf("%d\n", arr[i]);
}
