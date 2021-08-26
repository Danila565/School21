#include <stdio.h>
#include "../ex06/ft_str_is_printable.c"
int main()
{
	char a;
	for(int i = 0; i < 128; ++i)
	{
		a = i;
		if (ft_str_is_printable(&a))
			printf("%d : yes  ", i);
		else
			printf("%d : no!  ", i);
	}
	return 0;
}
