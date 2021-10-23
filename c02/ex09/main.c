#include <stdio.h>

char	*ft_strcapitalize(char *str);

int		main(void)
{
	char	str[] = "salut, asdf^^comment!@$&&<S-F9>*)*(tuzdfvas ? 42mots quaRAnte-deux; cinquante+et+un";

	printf(".%s.\n", ft_strcapitalize(str));
}

