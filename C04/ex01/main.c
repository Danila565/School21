#include <stdio.h>
int ft_putstr(char *str);
int main() 
{
	{
		char s1[100] = "abcde\0";
		ft_putstr(s1);
		printf("\n");
	}
	
	{
		char s1[100] = "\0";
		ft_putstr(s1);
		printf("\n");
	}
	
	{
		char s1[100] = " 123456789_\0";
		ft_putstr(s1);
		printf("\n");
	}
	
	return (0);
}

