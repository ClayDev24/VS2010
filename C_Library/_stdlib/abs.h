//F:\Pewter\Programming\C++\Tuts\C++ Reference Guide\www.cplusplus.com\reference\clibrary\cstdlib\atof.html
#include <stdio.h>	// Standard C lib.
#include <stdlib.h>	// Standard C lib.

void absolute() {
// Absolute Value:
	printf("abs(-11): %i\n", abs(-11)); // In C only int version exists.
// Absolute Value (Long Int):
	printf("labs(65537L)  : %ld\n", labs(65537L));
	printf("labs(-100000L): %ld\n", labs(-100000L));
}