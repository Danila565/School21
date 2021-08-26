#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max);

int	main(void)
{
	int min, max;
	scanf("%d%d", &min, &max);
	int *arr = ft_range(min, max);
	printf("pointer = %p\n", arr);
	for (int i = 0; i < max - min; ++i)
			printf("%d\n", arr[i]);
}
