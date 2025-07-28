#include <stdio.h>	// Standard C lib.
#include <string.h>	// Standard C lib.

void _strrchr() {
	char str[] = "This is a sample string";
	char *pch;
	// Locate last occurrence of character in string. Rear search.
	pch = strrchr(str, 's');
	printf("Last occurence of 's' found at %d \n", pch-str+1);
}