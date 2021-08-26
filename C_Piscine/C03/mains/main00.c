#include <stdio.h>
#include <string.h>

int ft_strcmp(char *s1, char *s2);

void check(int a, int b)
{
    a == b ? printf("OK: %d = %d\n", a, b) : printf("Error: %d = %d\n", a, b);
}

int main()
{
    {
        char s1[100] = "abcde\0";
        char s2[100] = "ab de\0";
        check(strcmp(s1, s2), ft_strcmp(s1, s2));
    }

    {
        char s1[100] = "abcde\0";
        char s2[100] = "abcde\0";
        check(strcmp(s1, s2), ft_strcmp(s1, s2));
    }

    {
        char s1[100] = "abcde\0";
        char s2[100] = "abcdec";
        check(strcmp(s1, s2), ft_strcmp(s1, s2));
    }

    {
        char s1[100] = "\0";
        char s2[100] = "\0";
        check(strcmp(s1, s2), ft_strcmp(s1, s2));
    }

    return (0);
}
