#include <stdio.h>
#include <string.h>
int ft_strlen(char *str);
void check(int a, int b) 
{
	a == b ? printf("OK: %d = %d\n", a, b) : printf("Error: %d = %d\n", a, b);
}
int main() 
{
	{
		char s1[100] = "abcde\0";
		check(strlen(s1), ft_strlen(s1));
	}
	
	{
		char s1[100] = "\0";
		check(strlen(s1), ft_strlen(s1));
	}
	
	{
		char s1[100] = " 123456789\0";
		check(strlen(s1), ft_strlen(s1));
	}
	
	return (0);
}
