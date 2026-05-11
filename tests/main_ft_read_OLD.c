#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

ssize_t	ft_read(int fd, void *buf, size_t count);

int	main(void)
{
	char	buf1[100];
	char	buf2[100];
	int	fd = open("tests/test.txt", O_RDONLY);

	if (fd < 0)
	{
		perror("open");
		return 1;
	}

	// ----- Standard read -----
	
	errno = 0;
	ssize_t r1 = read(fd, buf1, 11);
	printf("read   : %zd | errno %d (%s)\n", r1, errno, strerror(errno));

	lseek(fd, 0, SEEK_SET);

	// -------- ft_read --------
	
	errno = 0;
	ssize_t r2 = ft_read(fd, buf2, 11);
	printf("\nft_read: %zu | errno %d (%s)\n", r2, errno, strerror(errno));

	buf1[r1]='\0';
	buf2[r2]='\0';

	printf("\n[read]    \"%s\"\n", buf1);
	printf("\n[ft_read] \"%s\"\n", buf2);

	close(fd);
	return 0;
}
