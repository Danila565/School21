#include <stdio.h>

int ft_is_prime(int nb);

int main()
{
	for (int i = -5; i < 100; ++i)
	{
		if (ft_is_prime(i) == 1)
			printf("%d is prime\t", i);
	}
}
