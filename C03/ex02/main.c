#include <stdio.h>
#include <string.h>

char *ft_strcat(char *dest, char *src);

void check(char *a, char *b)
{
    !strcmp(a, b) ? printf("OK: %s = %s\n", a, b) : printf("Error: %s != %s\n", a, b);
}

int main()
{
    {
        char s1[100] = "abcde\0";
        char s2[100] = "ab de\0";
        check(strcat(s1, s2), ft_strcat(s1, s2));
    }

    {
        char s1[100] = "abcde\0";
        char s2[100] = "  b\0";
        check(strcat(s1, s2), ft_strcat(s1, s2));
    }
    return (0);
}
