#include <stdio.h>	// Standard C lib.
#include <string.h>	// Standard C lib.

void _strcmp() {
	char key[] = "apple";
	char guess[80];
	do {
		printf("Guess my favourite fruit? ");
		gets(guess);
	} while(strcmp(key, guess)); // 0=equal; >0=1st; <0=2nd
	puts("Correct answer!");
}