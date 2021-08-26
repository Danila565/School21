#include <stdio.h>
#include <unistd.h>
int	ft_count_if(char **tab, int length, int(*f)(char *));
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
	char	*tab[5] = {"Hel1lo", "df;kgndfng", "ds2gs", "sd3;fkmsdk"};
	tab[4] = NULL;
	int (*ptr)(char *a);
	int res;
	ptr = &ft_change;
	res = ft_count_if(tab, 4, ptr);
	printf("%d, ", res);
}
