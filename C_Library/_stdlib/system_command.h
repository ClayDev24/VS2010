//F:\Pewter\Programming\C++\Tuts\C++ Reference Guide\www.cplusplus.com\reference\clibrary\cstdlib\system.html
#include <stdio.h>	// Standard C lib.
#include <stdlib.h>	// Standard C lib.

void sys_cmd() {
	printf("Checking if processor is available...");
	if(system(NULL))
		puts("Ok");
    else
		exit(1);
	printf("Executing command DIR...\n");
	printf("The value returned was: %i.\n", system("dir")); // Returns int.
}

