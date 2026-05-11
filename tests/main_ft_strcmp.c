#include <stdio.h>
#include <string.h>

int ft_strcmp(const char *s1, const char *s2);

int main(void)
{
	const char *s1 = "hello";
	const char *s2 = "hello";
	
	printf("Comparing %s and %s\n", s1, s2);
	printf("ft_strcmp: %d\n", ft_strcmp(s1, s2));
	printf("strcmp   : %d\n", strcmp(s1, s2));
	
	const char *s3 = "hell";
	const char *s4 = "hello";
	
	printf("\nComparing %s and %s\n", s3, s4);
	printf("ft_strcmp: %d\n", ft_strcmp(s3, s4));
	printf("strcmp   : %d\n", strcmp(s3, s4));
	
	const char *s5 = "hello";
	const char *s6 = "helicopter";
	
	printf("\nComparing %s and %s\n", s5, s6);
	printf("ft_strcmp: %d\n", ft_strcmp(s5, s6));
	printf("strcmp   : %d\n", strcmp(s5, s6));

	const char *s7 = "z";
	const char *s8 = "a";
	
	printf("\nComparing %s and %s\n", s7, s8);
	printf("ft_strcmp: %d\n", ft_strcmp(s7, s8));
	printf("strcmp   : %d\n", strcmp(s7, s8));
	
	const char *s9 = "";
	const char *s10 = "";
	
	printf("\nComparing empty strings\n");
	printf("ft_strcmp: %d\n", ft_strcmp(s9, s10));
	printf("strcmp   : %d\n", strcmp(s9, s10));

	char *s11 = "";
	char *s12 = "a";
	
	printf("\nComparing empty string with %s\n", s12);
	printf("ft_strcmp: %d\n", ft_strcmp(s11, s12));
	printf("strcmp   : %d\n", strcmp(s11, s12));

	return 0; 
}
