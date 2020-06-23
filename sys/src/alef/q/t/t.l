#include <alef.h>

int	ff;
intern void
g(int)
{
}

intern int
f(int j)
{
	int k;
	k = ff & 7;
	g(k);
	return k;
}

void
main(int, byte**)
{
	f(3);
}
