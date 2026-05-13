#include <stdio.h>
#include <string.h>

char *ft_strcpy(char *dest, const char *src);

int main(void)
{
	char	*src = "source";
	char	dest[20] = "destination";

	printf("----- Standard copy -------------\n");
	printf("src is : %s\n", src);
	printf("dest is: %s\n", dest);
	
	char *ret = ft_strcpy(dest, src);
	
	printf("\nAfter running ft_strcpy(dest, src), \nsrc is : %s\ndest is: %s\n", src, dest);

	printf("\n----- Return value check --------\n");
	printf("dest address is  : %p\n", dest);
	printf("returned value is: %p\n", ret);

	char	*src2 = "";
	char 	dest2[20] = "destination";

	printf("\n----- Empty string copy ---------\n");
	printf("src is : %s\n", src2);
	printf("dest is: %s\n", dest2);

	ft_strcpy(dest2, src2);

	printf("\nAfter running ft_strcpy(dest, src), \nsrc is : %s\ndest is: %s\n", src2, dest2);

	return 0;
}
