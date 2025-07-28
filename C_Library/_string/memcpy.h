#include <stdio.h>	// Standard C lib.
#include <string.h>	// Standard C lib.

void _memcpy() {
	char src[] = "Sample string";
	char dest1[128];
	char dest2[128];
	memcpy(dest1, src, strlen(src)+1); // (dest, src, sz)
	memcpy(dest2, "copy successful", 16);  // countin' zero-terminated string.
	printf("src  : %s\n"
		   "dest1: %s\n"
		   "dest2: %s\n", src, dest1, dest2);
}
