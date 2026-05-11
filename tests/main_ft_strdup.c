#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

char	*ft_strdup(const char *s);

int	main(void)
{
	printf("----- Normal duplicate ------------------------------------\n");

	const char	*s = "Hello";

	printf("Original            : %s\n", s);

	errno = 0;
	char 	*dup = ft_strdup(s);

	if (dup == NULL)
	{
		printf("ft_strdup failed : errno %d (%s)\n", errno, strerror(errno));
    		return (1);
	}
	
	printf("Duplicate           : %s | errno : %d (%s)\n", dup, errno, strerror(errno));


	printf("\n----- Address check ---------------------------------------\n");

	printf("\nOriginal's address  : %p\n", s);
	printf("Duplicate's address : %p\n", dup);


	printf("\n----- Char replacement ------------------------------------\n");

	dup[0] = 'Y';
	
	printf("\nOriginal            : %s\n", s);
	printf("Duplicate (modified): %s\n", dup);

	free(dup);


	printf("\n----- Empty string ----------------------------------------\n");

	const char 	*s2 = "";
	
	printf("\nEmpty string        : %s\n", s2);

	errno = 0;
	char	*dup2 = ft_strdup(s2);

	if (dup2 == NULL)
	{
		printf("ft_strdup failed : errno %d (%s)\n", errno, strerror(errno));
    		return (1);
	}
	
	printf("Duplicate           : %s | errno : %d (%s)\n", dup2, errno, strerror(errno));

	free(dup2);


	printf("\n----- Big string --------------------------------------------\n");

	char	s3[100000];

	memset(s3, 'A', 99999);
	s3[99999] = '\0';

	printf("\nOriginal string\n");
	printf("length : %zu | first char : %c | last char : %c\n", strlen(s3), s3[0], s3[99998]);

	errno = 0;
	char 	*dup3 = ft_strdup(s3);

	if (dup3 == NULL)
	{
		printf("ft_strdup failed : errno %d (%s)\n", errno, strerror(errno));
    		return (1);
	}

	printf("\nBig string\n");
	printf("length : %zu | first char : %c | last char : %c\n", strlen(dup3), dup3[0], dup3[99998]);
	printf("errno  : %d (%s)\n", errno, strerror(errno));
	// printf("String		    : %s\n", dup3);
	
	free(dup3);

	return 0;
}

