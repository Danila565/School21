#include <stdio.h>
void ft_putnbr_base(int nbr, char *base);
int main()
{
	{
		int a = 0;
		char b[100] = "FdSGaA";
		ft_putnbr_base(a, b);
		printf("\n");
	}
	
	{
		int a = -4;
		char b[100] = "#z";
		ft_putnbr_base(a, b);
		printf("\n");
	}
	{
		int a = -2147483648;
		char b[100] = "aH";
		ft_putnbr_base(a, b);
		printf("\n");
	}
	{
		int a = 2147483647;
		char b[100] = "0123456789";
		ft_putnbr_base(a, b);
		printf("\n");
	}
	{
		int a = 5321;
		char b[100] = "abcdea";
		ft_putnbr_base(a, b);
		printf("\n");
	}
	{
		int a = -123;
		char b[100] = "gad-";
		ft_putnbr_base(a, b);
		printf("\n");
	}
	{
		int a = 5321;
		char b[100] = "a";
		ft_putnbr_base(a, b);
		printf("\n");
	}
	{
		int a = 5321;
		char b[100] = "";
		ft_putnbr_base(a, b);
		printf("\n");
	}
	
	return (0);
}
