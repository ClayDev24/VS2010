#include <stdio.h>	// Standard C lib.
#include <string.h>	// Standard C lib.
#include <errno.h>  // Standard C lib.

void _strerror() {
	FILE *pFile = fopen("unexist.ent", "r");
	if(!pFile)
		printf("Error opening file unexist.ent: %s\n", strerror(errno));
}