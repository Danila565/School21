#include <stdio.h>
#include "../ex09/ft_strcapitalize.c"
int main()
{
	char a[200] = "salUt, CoMmeNt tU vAs ? 42Mots quaRante-dEux; cinQuante+Et+un";
	printf("%s\n", ft_strcapitalize(a));
	return 0;
}
