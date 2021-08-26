#include <stdio.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find);


void check(char *a, char *b)
{
    if (!a && !b)
    {
        printf("OK: NULL\n");
        return ;
    }
    !strcmp(a, b) ? printf("OK: %s = %s\n", a, b) : printf("Error: %s != %s\n", a, b);
}

int main()
{
    {
        char s1[100] = "HELLO WORLD\0";
        char s2[100] = "LO W\0";
        check(strstr(s1, s2), ft_strstr(s1, s2));
    }

    {
        char s1[100] = "HELLO WORLD\0";
        char s2[100] = "\0";
        check(strstr(s1, s2), ft_strstr(s1, s2));
    }

    {
        char s1[100] = "HELLO WORLD\0";
        char s2[100] = "D\0";
        check(strstr(s1, s2), ft_strstr(s1, s2));
    }

    {
        char s1[100] = "HELLO WORLD\0";
        char s2[100] = "H\0";
        check(strstr(s1, s2), ft_strstr(s1, s2));
    }

    {
        char s1[100] = "HELLO WORLD\0";
        char s2[100] = "FaAFSgdfsa\0";
        check(strstr(s1, s2), ft_strstr(s1, s2));
    }
	{
        char s1[100] = "HELLO WORL\0";
        char s2[100] = "HELLO WORL\0";
        check(strstr(s1, s2), ft_strstr(s1, s2));
    }

    return (0);
}
