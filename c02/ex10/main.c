#include <string.h>
#include <stdio.h>

int main(void)
{
	char src[] = "123456";
	char dest[20];

	size_t ret = strlcpy(dest, src, 13);
	printf("%s, %zu", dest, ret);
}
