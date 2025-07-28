#include <stdio.h>	// Standard C lib.
#include <string.h>	// Standard C lib.

void _strncpy() {
	char scr[] = "To be or not to be";
	char dest[19];
	strncpy(dest, scr, 19);
	puts(dest);
}