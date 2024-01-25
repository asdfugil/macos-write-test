#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <limits.h>
#include <inttypes.h>

#define BYTES 2147483648

int main(void) {
        printf("Size_t = %zd\n", sizeof(size_t));
        printf("SSize_t = %zd\n", sizeof(ssize_t));
        printf("SIZE_MAX = %lu\n", ULONG_MAX);
        printf("SSIZE_MAX = %ld\n", LONG_MAX);
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
