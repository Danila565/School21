#include <stdio.h>
#include <unistd.h>
int	rush();
int	convert(char *str, int a[8][2]);
int main(int argc, char *argv[])
{
	int a[8][2];
	if (argc != 2)
	{
		write(1, "Error1\n", 7);
		return (0);
	}
	if(!convert(argv[1], a))
	{
		write(1, "Error2\n", 7);
		return (0);
	}
	if(!rush(a))
	{
		write(1, "Error\n", 7);
		printf("ooook\n");
	}
	return (0);
}
