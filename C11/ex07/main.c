#include <stdio.h>

void ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *));
int	ft_strcmp(char *a, char *b);
int main()
{
	char *arr[] = {"vlad", "HeLlo", "danila", "Danila", "", "fedya", "123", "12", "", 0};
	int	(*ptr)(char *, char *);
	ptr = &ft_strcmp;
	ft_advanced_sort_string_tab(arr, ptr);
	for(int i = 0;  i < 10; ++i)
		printf("%s\n", arr[i]);
}
