#include <stdio.h>
#include <string.h>
#include "../ex03/ft_strncat.c"
void check(char *a, char *b)
{
    !strcmp(a, b) ? printf("OK: %s = %s\n", a, b) : printf("Error: %s != %s\n", a, b);
}

int main()
{
    {
        char s1[100] = "abcde\0";
        char s2[100] = "ab de\0";
        check(strncat(s1, s2, 6), ft_strncat(s1, s2, 6));
    }

    {
        char s1[100] = "abcde\0";
        char s2[100] = "  b\0";
        check(strncat(s1, s2, 50), ft_strncat(s1, s2, 50));
    }
    return (0);
}
