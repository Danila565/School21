#include <stdio.h>
#include "../ex04/ft_str_is_lowercase.c"
int main()
{
	char a[25] = "";
	if (ft_str_is_lowercase(a))
		printf("low");
	else
		printf("no!");
	return 0;
}
