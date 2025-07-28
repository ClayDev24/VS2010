#include <stdio.h>	// Standard C lib.
#include <string.h>	// Standard C lib.

void _strtok() {
	char str[] ="- This, a sample string.";
	char *pch;
	printf("Splitting string \"%s\" into tokens:\n", str);
	pch = strtok(str," ,.-");
	while(pch) {
		printf("%s\n", pch);
		pch = strtok(NULL, " ,.-");
	}
}