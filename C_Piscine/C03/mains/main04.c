#include <stdio.h>
#include <string.h>
#include "../ex04/ft_strstr.c"
int main()
{
	{
		char a[] = "Just a common test, go away";
		char b[] = "test";
		printf("%s\n", strstr(a, b));
		printf("%s\n", ft_strstr(a, b));

	}
	{
		char a[] = "Just a common test, go away";
		char b[] = "";
		printf("%s\n", strstr(a, b));
		printf("%s\n", ft_strstr(a, b));

	}
	{
		char a[] = "Just a common test, go away";
		char b[] = "testik";
		printf("%s\n", strstr(a, b));
		printf("%s\n", ft_strstr(a, b));

	}
}
