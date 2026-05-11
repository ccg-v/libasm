#include <stdio.h>
#include <string.h>

size_t ft_strlen(const char *s);

int main (void)
{
	char *str = "hello";

	printf("String = %s\n", str);
	printf("ft_strlen: %zu\n", ft_strlen(str));
	printf("strlen   : %zu\n", strlen(str));


	char *str2 = "This string has 29 characters";
	printf("\nString = %s\n", str2);
	printf("ft_strlen: %zu\n", ft_strlen(str2));
	printf("strlen   : %zu\n", strlen(str2));

	 
	char *str3 = "";
	printf("\nString = %s\n", str3);
	printf("ft_strlen: %zu\n", ft_strlen(str3));
	printf("strlen   : %zu\n", strlen(str3));

	return 0;
}
