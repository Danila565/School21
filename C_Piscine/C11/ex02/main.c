#include <stdio.h>
#include <unistd.h>
int	ft_any(char **tab, int(*f)(char *));
int ft_change(char *a)
{
	int	i;
	i = 0;
	while (a[i] != '\0')
		if (a[i] >= '0' && a[i++] <= '9')
			return (1);
	return (0);
}
int	main()
{
	char	*tab[4] = {"Hello", "df;kgndfng", "dsgs"};
	tab[3] = NULL;
	int (*ptr)(char *a);
	int res;
	ptr = &ft_change;
	res = ft_any(tab, ptr);
	printf("%d, ", res);
}
