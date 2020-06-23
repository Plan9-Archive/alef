#include <alef.h>

int
dirstat(byte *file, Dir *dir)
{
	byte buf[DIRLEN];

	if(stat(file, buf, sizeof(buf)) == -1)
		return -1;
	convM2D(buf, dir);
	return 0;
}
