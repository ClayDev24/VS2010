#include <stdio.h>	// Standard C lib.
#include <string.h>	// Standard C lib.

void _memset() {
	char str[] = "almost every programmer should know memset!";
	memset(str, '-', 6);
	puts(str);
}
