#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

#define BYTES 2147483648

int main(void) {
	void* p = malloc(BYTES);
	printf("p=%p\n", p);
	if (!p) perror("malloc");
	int fd = open("file.bin", O_CREAT | O_WRONLY, 0600);
	if (fd == -1) perror("open");
	ssize_t ret = write(fd, p, BYTES);
	printf("ret=%zd\n", ret);
	if (ret == -1) printf("errno=%d (%s)\n", errno, strerror(errno));
	close(fd);
	return 0;
}
