#include <stdio.h>
#include <unistd.h>
int	*ft_map(int *tab, int length, int(*f)(int));
int ft_change(int a)
{
	return (a*2);
}
int	main()
{
	int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int (*ptr)(int a);
	int *res;
	ptr = &ft_change;
	res = ft_map(a, 10, ptr);
	for (int i = 0; i < 10; ++i)
		printf("%d, ", res[i]);
}
