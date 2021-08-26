#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_strdup(char *src);

int	main(void)
{
	char	*s1 = "Some TExt for my checking!!!\0Another Text"; 
	char	*s2 = "";
	char	*s3, *s4;                                                        
   	// s1[2] = 't';	
	s3 = ft_strdup(s1);
	s4 = ft_strdup(s2);
	printf("s1 = %s\n", s1);
	printf("s3 = %s\n", s3);
	printf("s4 = %s\n", s4);
	printf("strdup = %p\n", strdup(s2));
	printf("ft_strdup = %p\n", ft_strdup(s2));
	s4 = ft_strdup(s3);
	printf("strdup2 = %s\n", ft_strdup(s1));
}

