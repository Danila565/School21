#include <stdio.h>

int	ft_fibonacci(int index);

int	main(void)
{
	printf("1 = %d\n", ft_fibonacci(1));
	printf("0 = %d\n", ft_fibonacci(0));
	printf("-68 = %d\n", ft_fibonacci(-68));
	printf("5 = %d\n", ft_fibonacci(5));
	printf("17771 = %d\n", ft_fibonacci(22));
	printf("10946 = %d\n", ft_fibonacci(21));
}
