#include <stdio.h>
#include <string.h>
#include "../ex10/ft_strlcpy.c"
int main()
{
	char a[3] = "sdf";
	char b[6] = "hello\0";	
	char c[3] = "df";
	char d[6] = "hello\0";
	strlcpy(a, b, 3);
	ft_strlcpy(c, d, 3);
	printf("%s\n", a);
	printf("%s\n", c);
}
