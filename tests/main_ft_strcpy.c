#include <stdio.h>
#include <string.h>

char *ft_strcpy(char *dest, const char *src);

int main(void)
{
	char	*src1 = "source";
	char	*src2 = "source";
	char	dest1[20] = "destination";
	char	dest2[20] = "destination";

	printf("----- Standard copy -------------------------------------------\n");

	printf("\nBefore copying,\n");
	printf("src1 is  : %s\n", src1);
	printf("dest1 is : %s\n", dest1);
	printf("src2 is  : %s\n", src2);
	printf("dest2 is : %s\n", dest2);	
	
	char *ret1 = strcpy(dest1, src1);
	
	printf("\nAfter running strcpy(dest1, src1), \nsrc1 is  : %s\ndest1 is : %s\n", src1, dest1);

	char *ret2 = ft_strcpy(dest2, src2);
	
	printf("\nAfter running ft_strcpy(dest2, src2), \nsrc2 is  : %s\ndest2 is : %s\n", src2, dest2);


	printf("\n----- Return value check -----------------------------------\n");

	printf("\nAfter running strcpy(dest1, src1),\n");
	printf("dest1 address is  : %p\n", dest1);
	printf("returned value is : %p\n", ret1);

	printf("\nAfter running ft_strcpy(dest2, src)2,\n");
	printf("dest2 address is  : %p\n", dest2);
	printf("returned value is : %p\n", ret2);


	printf("\n----- Empty string copy ------------------------------------\n");

	char	*src3 = "";
	char	*src4 = "";
	char 	dest3[20] = "destination";
	char	dest4[20] = "destination";

	printf("\nBefore copying,\n");
	printf("src3 is  : %s\n", src3);
	printf("dest3 is : %s\n", dest3);
	printf("src4 is  : %s\n", src4);
	printf("dest4 is : %s\n", dest4);

	strcpy(dest3, src3);

	printf("\nAfter running ft_strcpy(dest3, src3), \nsrc3 is : %s\ndest3 is: %s\n", src3, dest3);

	ft_strcpy(dest4, src4);

	printf("\nAfter running ft_strcpy(dest4, src4), \nsrc4 is : %s\ndest4 is: %s\n", src4, dest4);

	return 0;
}
