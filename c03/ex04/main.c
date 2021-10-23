#include <stdio.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find);

int		main(void)
{
	char	*str;
	char	*to_find;

	char	*ptr;
	str = "Bonjour les chacaux";
	to_find = "lles";
	to_find = "ac";
	printf("ft :%s\n", ft_strstr(str, to_find));
	printf("st :%s\n", strstr(str, to_find));
	to_find = "onj";
	printf("ft :%s\n", ft_strstr(str, to_find));
	printf("st :%s\n", strstr(str, to_find));
	to_find = " l";
	printf("ft :%s\n", ft_strstr(str, to_find));
	printf("st :%s\n", strstr(str, to_find));
	to_find = "x";
	printf("ft :%s\n", ft_strstr(str, to_find));
	printf("st :%s\n", strstr(str, to_find));
}

