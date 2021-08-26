#include <stdio.h>
#include "../ex02/ft_swap.c"
int main()
{
	int a = 34;
	int b = 56;
	ft_swap(&a, &b);
	printf("%d, %d\n", a, b);
	return 0;
}

