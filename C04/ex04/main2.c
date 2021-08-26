#include <stdio.h>
 
void ft_putnbr_base(int nbr, char *base);
 
int main()
{
	{
		int a = 0;
		char b[100] = "FdSGaA";
		printf(":[%d, %s]", a, b);
		ft_putnbr_base(a, b);
		printf("\n");
	}
 
	{
		int a = -4;
		char b[100] = "#z";
		printf(":[%d, %s]", a, b);
		ft_putnbr_base(a, b);
		printf("\n");
	}
 
	{
		int a = -2147483648;
		char b[100] = "aH";
		printf(":[%d, %s]", a, b);
		ft_putnbr_base(a, b);
		printf("\n");
	}
 
	{
		int a = 2147483647;
		char b[100] = "0123456789";
		printf(":[%d, %s]", a, b);
		ft_putnbr_base(a, b);
		printf("\n");
	}
 
	{
		int a = 5321;
		char b[100] = "ab\tcd\ne";
		printf(":[%d, %s]", a, b);
		ft_putnbr_base(a, b);
		printf("\n");
	}
 
	{
		int a = -123;
		char b[100] = "gad-";
		printf(":[%d, %s]", a, b);
		ft_putnbr_base(a, b);
		printf("\n");
	}
	{
		int a = -123;
		char b[100] = "g";
		printf(":[%d, %s]", a, b);
		ft_putnbr_base(a, b);
		printf("\n");
	}
 
	return (0);
}
