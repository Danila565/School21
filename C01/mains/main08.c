#include <stdio.h>
#include "../ex08/ft_sort_int_tab.c"
int main()
{
	int a[7] = {100, 45, -66, 0 , 0,  34, 8};
	int size = 7;
	int i = 0;
	while(i != size)
	{
		printf("%d-", a[i]);
		++i;
	}
	i = 0;
	printf("\n");
	ft_sort_int_tab(a, size);	
	while(i != size)
	{
		printf("%d-", a[i]);
		++i;
	}
	return 0;
}
