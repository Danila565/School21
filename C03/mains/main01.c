#include <stdio.h>
#include <string.h>
 
int ft_strncmp(char *s1, char *s2, unsigned int n);
 
void check(int a, int b)
{
    a == b ? printf("OK: %d = %d\n", a, b) : printf("Error: %d = %d\n", a, b);
}
 
int main()
{
    {
        char s1[100] = "abcde\0";
        char s2[100] = "ab de\0";
        check(strncmp(s1, s2, 2), ft_strncmp(s1, s2, 2));
    }
 
    {
        char s1[100] = "abcde\0";
        char s2[100] = "ab de\0";
        check(strncmp(s1, s2, 4), ft_strncmp(s1, s2, 4));
    }
 
    {
        char s1[100] = "abcde\0";
        char s2[100] = "abcde\0";
        check(strncmp(s1, s2, 6), ft_strncmp(s1, s2, 6));
    }
 
    {
        char s1[100] = "abcde\0";
        char s2[100] = "abcdec";
        check(strncmp(s1, s2, 6), ft_strncmp(s1, s2, 6));
    }
 
    {
        char s1[100] = "\0";
        char s2[100] = "\0";
        check(strncmp(s1, s2, 3), ft_strncmp(s1, s2, 3));
    }
 
    return (0);
}
