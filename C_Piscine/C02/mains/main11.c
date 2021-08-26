#include <stdio.h>
#include <string.h>
#include "../ex11/ft_putstr_non_printable.c"
int main()
{
	char a[30] = "ab\ncde\tfgh\vijkl\aasd\e";
	//char b[30] = "Couc\noutu vas bien ?\0";
	ft_putstr_non_printable(a);
}
