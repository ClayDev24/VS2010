#include <stdio.h>	// Standard C lib.
#include <string.h>	// Standard C lib.

void _strncat() {
	char dest[20] = "To be ";
	char src[20]  = "or not to be";
	strncat(dest, src, 6); // (dest, src, num)
	puts(dest);
}