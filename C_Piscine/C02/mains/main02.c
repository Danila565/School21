#include <stdio.h>
#include "../ex02/ft_str_is_alpha.c"
int main()
{
	char a[26]= "";
	if(ft_str_is_alpha(a))
		printf("is_alpha");
	else
		printf("not_alpha");
	return 0;
}
