#include <stdio.h>
#include <string.h>

unsigned int ft_strlcat(char *dest, char *src, unsigned int size);

int main()
{
	{
		char a[50] = "Hello\0";
		char b[26] = "World, hail concatination\0";
		printf("%lu - %s\n", strlcat(a, b,  50), a);
		char c[50] = "Hello\0";
		char d[26] = "World, hail concatination\0";
		printf("%u - %s\n next \n", ft_strlcat(c, d,  50), c);
	}
	{
		char a[5] = "\0";
		char b[26] = "World, hail concatination\0";
		char c[50] = "\0";
		char d[26] = "World, hail concatination\0";
		printf("%lu - %s\n", strlcat(a, b,  5), a);
		printf("%u - %s\n next \n", ft_strlcat(c, d,  5), c);
	}
	{
		char a[50] = "Hello\0";
		char b[25] = "\0";
		printf("%lu - %s\n", strlcat(a, b,  50), a);
		char c[50] = "Hello\0";
		char d[26] = "\0";
		printf("%u - %s\n next \n", ft_strlcat(c, d,  50), c);
	}
}
