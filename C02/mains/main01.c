#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "../ex01/ft_strncpy.c"
int main()
{
	char a[15] = "gfhf-_jfgawerj\0";
	char b[15] = "hell\0";	
	//char c[15] = "ghjghjghjj\0";
	//char d[15] = "hell\0";
	//strncpy(a, b, 5);
	ft_strncpy(a, b, 5);
	//printf("%s\n", a);
	write(1, a, 15);
	//printf("%s\n", c);
}
