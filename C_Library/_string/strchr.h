#include <stdio.h>	// Standard C lib.
#include <string.h>	// Standard C lib.

void _strchr() {
	char str[] = "This is a sample string";
	char *pch;
	printf("Looking for the 's' character in: \"%s\"...\n", str);
	pch = strchr(str, 's');
	while(pch) {
		printf("found at %d\n", pch-str+1);
		pch = strchr(pch+1, 's'); //Next?
	}
}