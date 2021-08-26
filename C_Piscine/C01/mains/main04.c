#include <stdio.h>
#include "../ex04/ft_ultimate_div_mod.c"
int main()
{
	int a = 29;
	int b = 9;
	ft_ultimate_div_mod(&a, &b);
	printf("%d  %d\n", a, b);
	return 0;
}
