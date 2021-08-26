#include <stdio.h>
#include <unistd.h>
#include "../ex12/ft_print_memory.c"
/*char hexadecimal(int a)
{	
	if (a >= 0 && a <= 9)
		return (a + '0');
	else
		return ((a % 10) + 'a');
}
void int_to_char(unsigned long a)
{
	char tmp[16];
	int i = 0;
	while (i < 16)
	{
		tmp[15-i] = hexadecimal(a % 16);
		a /= 16;
		++i;
	}
	write(1, tmp, 16);
}
*/
int main()
{
	char *a = "\tdkf\vdfso\ngho\0uhfioshfoudshfohsdoushdfjsdighsdohgousdhsdohsdofdgddfg";
	void *p = a;
	//unsigned long i = (unsigned long) p;
	//printf("point - %p\n int - %lu", p, i);
	//int_to_char(i);
	ft_print_memory(p, 28);
	return 0;
}
