//F:\Pewter\Programming\C++\Tuts\C++ Reference Guide\www.cplusplus.com\reference\clibrary\cstdlib\getenv.html
#include <stdio.h>	// Standard C lib.
#include <stdlib.h>	// Standard C lib.

void get_environment() {
	char *pPath = getenv("PATH"); // Gets environment variables path:
	if(pPath)
		printf("The current path is: %s", pPath);
}