#include <stdio.h>

int	ft_recursive_power(int nb, int power);

int	main(void)
{
	printf("-5^2 = %d\n", ft_recursive_power(-5, 2));
	printf("5^-2 = %d\n", ft_recursive_power(5, -2));
	printf("0^0 = %d\n", ft_recursive_power(0, 0));
	printf("0^25 = %d\n", ft_recursive_power(0, 25));
	printf("5^0 = %d\n", ft_recursive_power(5, 0));
	printf("-4^3 = %d\n", ft_recursive_power(-4, 3));
	printf("6^6 = %d\n", ft_recursive_power(6, 6));
	printf("12^2 = %d\n", ft_recursive_power(12, 2));
	printf("2147483647^1 = %d\n", ft_recursive_power(2147483647, 1));
}
