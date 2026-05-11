#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

ssize_t	ft_read(int fd, void *buf, size_t count);

int main(void)
{
	char	buf1[450];
	char	buf2[450];
	int	err1;
	int	err2;
	int	fd = open("tests/test.txt", O_RDONLY);

	if (fd < 0)
	{
		perror("open");
		return 1;
	}
	

	printf("\n----- Normal read -------------------------------------------\n");

	errno = 0;
	ssize_t r1 = read(fd, buf1, 450);
	err1 = errno;

	lseek(fd, 0, SEEK_SET);

	errno = 0;
	ssize_t r2 = ft_read(fd, buf2, 450);
	err2 = errno;

	if (r1 >= 0)
		buf1[r1] = '\0';
	if (r2 >= 0)
		buf2[r2] = '\0';

	printf("read    : %s\n", buf1);
	printf("return  : %zd | errno %d (%s)\n", r1, err1, strerror(err1));
	
	printf("\nft_read : %s\n", buf2);
	printf("return  : %zd | errno %d (%s)\n", r2, err2, strerror(err2));


	printf("\n----- Partial read ------------------------------------------\n");

	lseek(fd, 0, SEEK_SET);

	errno = 0;
	r1 = read(fd, buf1, 12);
	err1 = errno;
	
	lseek(fd, 0, SEEK_SET);

	errno = 0;
	r2 = ft_read(fd, buf2, 12);
	err2 = errno;

	if (r1 >= 0)
		buf1[r1] = '\0';
	if (r2 >= 0)
		buf2[r2] = '\0';

	printf("read    : %s\n", buf1);
    	printf("return  : %zd | errno %d (%s)\n", r1, err1, strerror(err1));

    	printf("\nft_read : %s\n", buf2);
    	printf("return  : %zd | errno %d (%s)\n", r2, err2, strerror(err2));
	

	printf("\n----- EOF test ----------------------------------------------\n");

	lseek(fd, 0, SEEK_SET);
	
	errno = 0;
	r1 = read(fd, buf1, 450);
	err1 = errno;

	printf("read\n");
	printf("first read   : %zd | errno %d (%s)\n", r1, err1, strerror(err1));

	errno = 0;
	r1 = read(fd, buf1, 1);
	err2 = errno;

	printf("second read  :   %zd | errno %d (%s)\n", r1, err2, strerror(err2));

	lseek(fd, 0, SEEK_SET);
	
	errno = 0;
	r2 = ft_read(fd, buf2, 450);
	err1 = errno;

	printf("\nft_read\n");
	printf("first read   : %zd | errno %d (%s)\n", r2, err1, strerror(err1));

	errno = 0;
	r2 = ft_read(fd, buf2, 1);
	err2 = errno;
	printf("second read  :   %zd | errno %d (%s)\n", r2, err2, strerror(err2));


	printf("\n----- Zero bytes --------------------------------------------\n");

	lseek(fd, 0, SEEK_SET);
	
	errno = 0;
	r1 = read(fd, buf1, 0);
	err1 = errno;

	lseek(fd, 0, SEEK_SET); 

	errno = 0;
	r2 = ft_read(fd, buf2, 0);
	err2 = errno;

	printf("read    : %zd | errno %d (%s)\n", r1, err1, strerror(err1));
	printf("ft_read : %zd | errno %d (%s)\n", r2, err2, strerror(err2));


 	printf("\n----- Invalid fd --------------------------------------------\n");

	errno = 0;
	r1 = read(-42, buf1, 12);
	err1 = errno;

	errno = 0;
	r2 = ft_read(-42, buf2, 10);
	err2 = errno;

	printf("read    : %zd | errno %d (%s)\n", r1, errno, strerror(err1));
	printf("ft_read : %zd | errno %d (%s)\n", r2, errno, strerror(err2));


/*	printf("\n----- NULL buffer (UNSAFE TEST) -----------------------------\n");

	// This test is intentionally disabled because
	// read(NULL, ...) triggers compile-time warnings with -Werror
	// At runtime it would return -1 and set errno = EFAULT (bad address)

	errno = 0;
	r1 = read(fd, NULL, 12);
	err1 = errno;

	printf("read    : %zd | errno %d (%s)\n", r1, errno, strerror(err1));

 	errno = 0;
	r2 = ft_read(fd, NULL, 12);
	err2 = errno;
	printf("ft_read : %zd | errno %d (%s)\n", r2, errno, strerror(err2));
*/

	printf("\n----- Closed fd test ----------------------------------------\n");

	close(fd);

	errno = 0;
	r1 = read(fd, buf1, 12);
	err1 = errno;

	errno = 0;
	r2 = ft_read(fd, buf2, 12);
	err2 = errno;

	printf("read    : %zd | errno %d (%s)\n",r1, err1, strerror(err1));
	printf("ft_read : %zd | errno %d (%s)\n",r2, err2, strerror(err2));

	return 0;
}
