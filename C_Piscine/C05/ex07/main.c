#include <stdio.h>

int ft_find_next_prime(int nb);

int main()
{
	printf("%d next is %d\n", -25, ft_find_next_prime(-25));
	printf("%d next is %d\n", 1, ft_find_next_prime(1));
	printf("%d next is %d\n", 1010, ft_find_next_prime(1010));
	printf("%d next is %d\n", 1302, ft_find_next_prime(1302));
	printf("%d next is %d\n", 2394, ft_find_next_prime(2394));
	printf("%d next is %d\n", 3558, ft_find_next_prime(3558));
	printf("%d next is %d\n", 3559, ft_find_next_prime(3559));
	printf("%d next is %d\n", 3571,ft_find_next_prime(3571));
	printf("%d next is %d\n", 2147483645, ft_find_next_prime(2147483645));
	printf("%d next is %d\n", 2147483647, ft_find_next_prime(2147483647));
}
