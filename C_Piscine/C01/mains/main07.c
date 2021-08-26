#include <stdio.h>
#include "../ex07/ft_rev_int_tab.c"
int main()
{
	int a[6] = {1,2,3,4,5,6};
	int size = 6;
	ft_rev_int_tab(a, size);
	for(int i = 0; i < size; ++i)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
