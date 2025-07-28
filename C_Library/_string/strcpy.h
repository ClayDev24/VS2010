#include <stdio.h>	// Standard C lib.
#include <string.h>	// Standard C lib.

void _strcpy() {
	char src[] = "Sample string";
	char dest1[40];
	char dest2[40];
	strcpy(dest1, src); // (dest*, src*)
	strcpy(dest2, "copy successful");
	printf("str1: %s\n"
		   "str2: %s\n"
		   "str3: %s\n", src, dest1, dest2);
}