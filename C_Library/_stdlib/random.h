//F:\Pewter\Programming\C++\Tuts\C++ Reference Guide\www.cplusplus.com\reference\clibrary\cstdlib\rand.html
#include <stdio.h>	// Standard C lib.
#include <stdlib.h>	// Standard C lib.
#include <time.h>	// Standard C lib.
//#include <cstdio>	// Standard C lib in C++ lib.
//#include <cstdlib>// Standard C lib in C++ lib.
//#include <ctime>
//using namespace std; // Used with Borland C++ compiler.

void random() {
	int iSecret, iGuess;
// rand:
	/* initialize random seed: */
	srand(time(NULL));
	/* generate secret number: */
	iSecret = rand() % 10+1;	
	do {
		printf("Guess the number (1 to 10): ");
		scanf("%d", &iGuess);
		if(iSecret<iGuess)
			puts("The secret number is lower\n");
		else if(iSecret>iGuess)
			puts("The secret number is higher\n");
	} while(iSecret!=iGuess);	
	puts("Ya got it!");
// srand:
	printf("First number: %d\n", rand() % 100);
	srand (time(NULL));
	printf("Random number: %d\n", rand() % 100);
	srand (1);
	printf("Again the first number: %d\n", rand() %100);
	printf("Again the second number: %d\n", rand() %100);

	return 0;
}
