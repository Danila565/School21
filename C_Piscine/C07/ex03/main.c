#include <stdio.h>
#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep);

int	main(int argc, char *argv[])
{	
	char *c = ft_strjoin(argc, argv, "<=>");
	printf("%s\n", c);
}
