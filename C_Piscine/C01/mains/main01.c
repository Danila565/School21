#include <stdio.h>
#include "../ex01/ft_ultimate_ft.c"
int main()
{
	int a = 4;
	int *ptr = &a;
	int **ptr2 = &ptr;
	int ***ptr3 = &ptr2;
	int ****ptr4 = &ptr3;
	int *****ptr5 = &ptr4;
	int ******ptr6 = &ptr5;
	int *******ptr7 = &ptr6;
	int ********ptr8 = &ptr7;
	int *********ptr9 = &ptr8;
	ft_ultimate_ft(ptr9);
	printf("%d\n", a);
	return 0;
}
