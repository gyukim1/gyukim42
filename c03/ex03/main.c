#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb);

int		main(void)
{
	char	dest[50] = "test dest";
	char	*src;
	
	char	dest1[50] = "test dest";
	src = " test src";
	printf(".%s.\n", ft_strncat(dest, src, 3));
	printf(".%s.\n", strncat(dest1, src, 3));
}

