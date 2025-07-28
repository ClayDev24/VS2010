#include <stdio.h>	// Standard C lib.
#include <string.h>	// Standard C lib.

void _strspn() {
	char str[]  = "129th";
	char cset[] = "1234567890";
	printf("The length of initial number is %d.\n", strspn(str, cset));
}