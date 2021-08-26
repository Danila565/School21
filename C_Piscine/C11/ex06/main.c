#include <stdio.h>

void ft_sort_string_tab(char **tab);
int	ft_strcmp(char *a, char *b);
int main()
{
	char *arr[] = {"vlad", "HeLlo", "danila", "Danila", "", "fedya", "123", "12", "", 0};
	ft_sort_string_tab(arr);
	for(int i = 0;  i < 10; ++i)
		printf("%s\n", arr[i]);
}
