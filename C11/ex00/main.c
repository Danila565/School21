#include <unistd.h>
void ft_foreach(int *tab, int length, void(*f)(int));
void ft_putnbr(int a)
{
	char	tmp;
	tmp = '0' + a;
	write(1, &tmp, 1);
}
int	main()
{
	int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	void (*ptr)(int a);
	ptr = &ft_putnbr;
	ft_foreach(a, 10, ptr);
}
