#include <stdio.h>

int	ft_iterative_factorial(int nb);

int	main(void)
{
	printf("-5! = %d\n", ft_iterative_factorial(-5));
	printf("0! = %d\n", ft_iterative_factorial(0));
	printf("1! = %d\n", ft_iterative_factorial(1));
	printf("2! = %d\n", ft_iterative_factorial(2));
	printf("6! = %d\n", ft_iterative_factorial(6));
	printf("12! = %d\n", ft_iterative_factorial(12));
}
