#include <stdio.h>	// Standard C lib.
#include <string.h>	// Standard C lib.

// Locate Substring:
void _strstr() {
	char str[] = "This is a simple string";
	char *pch;
	pch = strstr(str, "simple");
	strncpy(pch, "sample", 6);
	puts(str);
}