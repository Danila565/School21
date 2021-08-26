#include <stdio.h>
#include "../ex03/ft_str_is_numeric.c"
int main()
{
	char a[25] = "";
	if(ft_str_is_nimeric(a))
		printf("numeric");
	else
		printf("not_numeric");
	return 0;
}
