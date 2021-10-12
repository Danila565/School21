#include <stdio.h>
#include <stdlib.h>
int  ft_atoi(char *str);
void check(int a, int b)
{
	a == b ? printf("OK: %d = %d\n", a, b) : printf("Error: %d = %d\n", a, b);
}
int main()
{
	{
		char s1[100] = "12345\0";
		check(atoi(s1), ft_atoi(s1));
	}
	{
		char s1[100] = "  -12345\0";
		check(atoi(s1), ft_atoi(s1));
	}

	{
		char s1[100] = "  \f\n\r\t\v+--12345\0";
		printf("%d\n", ft_atoi(s1));
	}
	{
		char s1[100] = "  ---+--+1234ab567";
		printf("%d\n", ft_atoi(s1));
	}
	{
		char s1[100] = " ++---005\0";
		printf("%d\n", ft_atoi(s1));
	}
	{
		char s1[100] = "0\0";
		check(atoi(s1), ft_atoi(s1));
	}
	{
		char s1[100] = "\0";
		check(atoi(s1), ft_atoi(s1));
	}
	{
		char s1[100] = "      ++-abbc";
		check(atoi(s1), ft_atoi(s1));
	}
	{
		char s1[100] = "      !";
		check(atoi(s1), ft_atoi(s1));
	}
	{
		char s1[100] = "a";
		check(atoi(s1), ft_atoi(s1));
	}
	{
		char s1[100] = "--+";
		check(atoi(s1), ft_atoi(s1));
	}
	{
		char s1[100] = "-2147483648";
		check(atoi(s1), ft_atoi(s1));
	}
	{
		char s1[100] = "2147483647";
		check(atoi(s1), ft_atoi(s1));
	}
	{
		char s1[100] = "--1234";
		check(atoi(s1), ft_atoi(s1));
	}

	return (0);
}
