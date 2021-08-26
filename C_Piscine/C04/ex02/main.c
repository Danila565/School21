#include <stdio.h>
void	ft_putnbr(int nb);
int main() 
{
	{
		int number = 54321;
		ft_putnbr(number);
		printf("\n");
	}
	{
		int number = -12345;
		ft_putnbr(number);
		printf("\n");
	}
	{	
		int number = 123;
		ft_putnbr(number);
		printf("\n");
	}
	{
		int number = 0;
		ft_putnbr(number);
		printf("\n");
	}
	
	{
		int number = 2147483647;
		ft_putnbr(number);
		printf("\n");
	}
	{
		int number = -2147483648;
		ft_putnbr(number);
		printf("\n");
	}
	return (0);
}
