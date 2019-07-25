#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int main(int ac, char **av)
{
	char buffer[2000001];
	size_t len = 2000000;
	int fd;
	size_t size;
	size_t tmp;

	if (ac < 2)
		return (0);
	size = 0;
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (0);
	while ((tmp = read(fd, buffer, len)))
		size += tmp;
	printf("Size file : %zu\n", size);
}
