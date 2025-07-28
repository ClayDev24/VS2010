#include <stdio.h>	// Standard C lib.
#include <string.h>	// Standard C lib.

void _memmov() {
	char src[] = "memmove can be very useful......"; // (dest, src, sz)
	memmove(src+20, src+15, 11); //Can overlap dest n' src.
	puts(src);
}