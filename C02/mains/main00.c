#include <string.h>
#include <stdio.h>
#include "../ex00/ft_strcpy.c"
int main()
{
	char a[15] = "sdassad";
	char b[15] = "abcd";
	char c[15] = "iabcd";
	char d[15] = "adfgfdgd\0";
	strcpy(a, b);
	printf("%s\n", a);
	printf("%s\n", ft_strcpy(d, c));
	return 0;
}
