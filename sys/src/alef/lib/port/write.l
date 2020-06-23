#include <alef.h>

int
write(int fd, void *buf, int n)
{
	return pwrite(fd, buf, n, -1);
}
