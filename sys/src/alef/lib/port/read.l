#include <alef.h>

int
read(int fd, void *buf, int n)
{
	return pread(fd, buf, n, -1);
}
