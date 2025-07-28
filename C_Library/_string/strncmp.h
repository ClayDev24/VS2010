#include <stdio.h>	// Standard C lib.
#include <string.h>	// Standard C lib.

void _strncmp() {
	char str[][5] = {"R2D2", "C3PO" ,"R2A6"};
	int i;
	puts("Looking for R2 astromech droids...");
	for(i=0; i<3; i++)
		if(strncmp(str[i],"R2xx",2) == 0) // 0=equal; >0=1st>; <0=2nd
			printf("found %s\n", str[i]);
}