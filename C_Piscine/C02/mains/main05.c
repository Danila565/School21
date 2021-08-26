#include <stdio.h>
#include "../ex05/ft_str_is_uppercase.c"
int main()
{
	char a[25] = "DSOUFD@HGSG\0";
	if (ft_str_is_uppercase(a))
		printf("upper");
	else
		printf("no!");
	return 0;
}
