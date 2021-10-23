#include <bsd/string.h>
#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
int main(void)
{
	char dest[50] = "abc ";
	char src[50] = "defg";

	printf("%u\n", ft_strlcat(dest, src, 1));
	printf("%s\n", dest);		
	return 0;
}
