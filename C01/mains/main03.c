#include <stdio.h>
#include "../ex03/ft_div_mod.c"
int main()
{
	int a = 29;
	int b = 9;
	int div, mod;
	ft_div_mod(a, b, &div, &mod);
	printf("%d, %d, --- %d, %d", a, b, div, mod);
	return 0;
}
