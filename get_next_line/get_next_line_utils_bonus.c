
#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*res;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (size < start + 1)
		len = 0;
	if (len < (size - start))
		len = len + 1;
	else
		len = size - start + 1;
	res = (char *) malloc(sizeof(char) * len);
	if (!res)
		return (NULL);
	ft_strlcpy(res, (char *) &s[start], len);
	return (res);
}

char	*ft_strchr(const char *s, int a)
{
	char	c;
	char	*p;

	p = (char *) s;
	c = (char) a;
	while (*p != '\0')
	{
		if (c == *p)
			return (p);
		++p;
	}
	if (c == *p)
		return (p);
	return (NULL);
}

int	ft_strlcpy(char *dest, char *src, size_t n)
{
	size_t	i;
	char	*s;

	s = src;
	i = n;
	if (i != 0)
	{
		while (--i != 0)
		{
			*dest++ = *s++;
			if ((*(dest - 1)) == 0)
				break ;
		}
	}
	if (i == 0)
	{
		if (n != 0)
			*dest = '\0';
		while (*s++)
			;
	}
	return (s - src - 1);
}

size_t	ft_strlen(const char *c)
{
	size_t	len;

	len = 0;
	while (c[len])
		++len;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2, size_t n)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	res = (char *) malloc(sizeof(char) * (ft_strlen(s1) + n + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		++i;
	}
	res[i] = s1[i];
	j = 0;
	while (j < n)
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}