#include <stdio.h>
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int main()
{
	char a[100] = "F", b[100] = "0123456789ABCDEF", c[100] = "01";
	printf("nbr = %s\nFrom = %s\t To = %s\n res = %s\n", a, b, c, ft_convert_base(a, b, c));
	while (scanf("%s%s%s", a, b, c))
	{
		printf("nbr = %s\nFrom = %s\t To = %s\n res = %s\n", a, b, c, ft_convert_base(a, b, c));
	}
}
