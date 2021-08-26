#include <stdio.h>
#include <unistd.h>
int	ft_is_sort(int *tab, int length, int(*f)(int, int));
int ft_change(int a, int b)
{
	if (a < b)
		return (-5);
	return (5);
}
int	main()
{
	int	tab[10] = {2, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int (*ptr)(int a, int b);
	int res;
	ptr = &ft_change;
	res = ft_is_sort(tab, 10, ptr);
	printf("%d, ", res);
}
