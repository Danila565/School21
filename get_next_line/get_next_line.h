
#ifndef GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
#ifndef BUFFSIZE
# define BUFFSIZE 1
#endif
# define MAX_FD 10240

char	*get_next_line(int fd);
size_t	ft_strlen(const char *c);
char	*ft_strjoin(char const *s1, char const *s2, size_t n);
char	*ft_strchr(const char *s, int a);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strlcpy(char *dest, char *src, size_t n);
#endif
