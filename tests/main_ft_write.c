#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

ssize_t ft_write(int fd, const void *buf, size_t count);

int main(void)
{
	const char *line = "Assembly is cool\n";

	printf("----- Normal write --------------------------------------------\n");
	
	errno = 0;
	ssize_t ret1 = write(1, line, strlen(line));
	printf("write returns    : %zd | errno : %d (%s)\n\n", ret1, errno, strerror(errno));

	errno = 0;
	ssize_t ret2 = ft_write(1, line, strlen(line));
	printf("ft_write returns : %zd | errno : %d (%s)\n", ret2, errno, strerror(errno));


	printf("\n----- Zero bytes ----------------------------------------------\n");

	errno = 0;
	ssize_t ret3 = write(1, line, 0);
	printf("write returns    :  %zd | errno : %d (%s)\n\n", ret3, errno, strerror(errno));

	errno = 0;
	ssize_t ret4 = ft_write(1, line, 0);
	printf("ft_write returns :  %zd | errno : %d (%s)\n", ret4, errno, strerror(errno));


	printf("\n----- Invalid pointer  ----------------------------------------\n");

	char *ptr = (char *)0x1;

	errno = 0;
	ssize_t ret5 = write(1, ptr, 5);
	printf("write returns    : %zd | errno %d (%s)\n", ret5, errno, strerror(errno));

	errno = 0;
	ssize_t ret6 = ft_write(1, ptr, 5);
	printf("ft_write returns : %zd | errno %d (%s)\n", ret6, errno, strerror(errno));


	printf("\n----- Invalid fd ----------------------------------------------\n");

	errno = 0;
	ssize_t ret7 = write(-42, line, strlen(line));
	printf("write returns    : %zd | errno %d (%s)\n", ret7, errno, strerror(errno));

	errno = 0;
	ssize_t ret8 = ft_write(-42, line, strlen(line));
	printf("ft_write returns : %zd | errno %d (%s)\n", ret8, errno, strerror(errno));


	printf("\n----- Closed fd -----------------------------------------------\n");

	close(1);

	errno = 0;
	ssize_t ret9 = write(1, line, strlen(line));
	fprintf(stderr, "write returns    : %zd | errno %d (%s)\n", ret9, errno, strerror(errno));

	errno = 0;
	ssize_t ret0 = ft_write(1, line, strlen(line));
	fprintf(stderr, "ft_write returns : %zd | errno %d (%s)\n", ret0, errno, strerror(errno));

	return 0;
}
