#include <stdio.h>	// Standard C lib.
#include <string.h>	// Standard C lib.

void _strcspn() {
	char  str[] = "fcba73";
	char keys[] = "1234567890";
	printf("The first number in str is at position %d.\n", strcspn(str, keys)+1);
}