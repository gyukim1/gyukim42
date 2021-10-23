#include <stdio.h>
#include <string.h>

char	*ft_strcat(char *dest, char *src);

int		main(void)
{
	char	dest[50] = "test dest";
	char	*src;
	
	char	dest1[50] = "test dest";
	src = " test src";
	printf(".%s.\n", ft_strcat(dest, src));
	printf(".%s.\n", strcat(dest1, src));
}

