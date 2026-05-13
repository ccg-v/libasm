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

	printf("\nOriginal                 : %s\n", s);

	errno = 0;
	char 	*dup1 = strdup(s);
	int 	err1 = errno;

	if (dup1 == NULL)
	{
		printf("strdup failed : errno %d (%s)\n", err1, strerror(err1));
    		return (1);
	}
	
	printf("Duplicate with strdup    : %s | errno : %d (%s)\n", dup1, err1, strerror(err1));

	errno = 0;
	char 	*dup2 = ft_strdup(s);
	int	err2 = errno;

	if (dup2 == NULL)
	{
		printf("ft_strdup failed : errno %d (%s)\n", err2, strerror(err2));
    		return (1);
	}
	
	printf("Duplicate with ft_strdup : %s | errno : %d (%s)\n", dup2, err2, strerror(err2));

	
	printf("\n----- Address check ---------------------------------------\n");

	printf("\nOriginal string address  : %p\n", (void *)s);
	printf("Duplicate with strdup    : %p\n", (void *)dup1);
	printf("Duplicate with ft_strdup : %p\n", (void *)dup2);

	printf("\n----- First char replacement ------------------------------\n");

	dup1[0] = 'Y';
	dup2[1] = 'A';
	
	printf("\nOriginal string          : %s\n", s);
	printf("Duplicate with strdup    : %s\n", dup1);
	printf("Duplicate with ft_strdup : %s\n", dup2);
	
	free(dup1);
	free(dup2);

	printf("\n----- Empty string ----------------------------------------\n");

	const char 	*s2 = "";
	
	printf("\nEmpty string             : %s\n", s2);
  
	errno = 0;
	char	*dup3 = strdup(s2);
	int	err3 = errno;

	if (dup3 == NULL)
	{
		printf("strdup failed : errno %d (%s)\n", err3, strerror(err3));
    		return (1);
	}
	
	printf("Duplicate with strdup    : %s | errno : %d (%s)\n", dup3, err3, strerror(err3));

	errno = 0;
	char	*dup4 = ft_strdup(s2);
	int	err4 = errno;

	if (dup4 == NULL)
	{
		printf("ft_strdup failed : errno %d (%s)\n", err4, strerror(err4));
    		return (1);
	}
	
	printf("Duplicate with ft_strdup : %s | errno : %d (%s)\n", dup4, err4, strerror(err4));

	free(dup3);
	free(dup4);


	printf("\n----- Big string ------------------------------------------\n");

	char	s3[100000];

	memset(s3, 'A', 99999);
	s3[99999] = '\0';

	printf("\nOriginal string\n");
	printf("length : %zu | first char : %c | last char : %c\n", strlen(s3), s3[0], s3[99998]);

	errno = 0;
	char 	*dup5 = strdup(s3);
	int	err5 = errno;

	if (dup5 == NULL)
	{
		printf("strdup failed : errno %d (%s)\n", err5, strerror(err5));
    		return (1);
	}

	printf("\nDuplicate with strdup\n");
	printf("length : %zu | first char : %c | last char : %c\n", strlen(dup5), dup5[0], dup5[99998]);
	printf("errno  : %d (%s)\n", err5, strerror(err5));
	// printf("String		    : %s\n", dup5);

	errno = 0;
	char 	*dup6 = ft_strdup(s3);
	int	err6 = errno;
	if (dup6 == NULL)
	{
		printf("ft_strdup failed : errno %d (%s)\n", err6, strerror(err6));
    		return (1);
	}

	printf("\nDuplicate with ft_strdup\n");
	printf("length : %zu | first char : %c | last char : %c\n", strlen(dup6), dup6[0], dup6[99998]);
	printf("errno  : %d (%s)\n", err6, strerror(err6));
	// printf("String		    : %s\n", dup6);

	free(dup5);
	free(dup6);

	return 0;
}

