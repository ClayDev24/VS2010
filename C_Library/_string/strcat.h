#include <stdio.h>	// Standard C lib.
#include <string.h>	// Standard C lib.

void _strcat() {
	char dest[80] = "these ";
	char *src     = "strings are ";
	strcat(dest, src);
	puts(strcat(dest, "concatenated."));
}
