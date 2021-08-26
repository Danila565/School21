#include <stdio.h>

int	ft_sqrt(int nb);

int sqrt1(int nb)
{
	if (nb <= 0)
		return (0);
	int	tmp = 0;
	while (tmp * tmp < nb)
	{
		++tmp;
	}
	if (tmp * tmp == nb)
		return (tmp);
	return (0);
}

int	main(void)
{
	for (int i = 10000; i <= 20000; ++i)
	{
		if (ft_sqrt(i) != sqrt1(i))
			printf("Error %d: %d != %d !\n", i, sqrt1(i), ft_sqrt(i));
	}
}
