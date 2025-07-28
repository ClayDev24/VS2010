#include <iostream>
#include <stdio.h>
// Function Prototypes:
void odd(int a);
void even(int); // Compiler checks the type pars. The identifier is optional, used jus'to clarify for readers.

int main () {
	int i;
	do {
		printf("Type a number (0 to exit): ");
		scanf("%i", &i);
		odd(i);
	} while(i!=0);

	system("pause");
	return(0);
}

void odd(int a) {
	if ((a%2)!=0)
		printf("Number is odd.\n");
	else even(a);
}

void even(int a) { // identifier is needed in C, but not in C++ (used to reserve space for future inclusions). 
	if ((a%2)==0)
		printf("Number is even.\n");
	else odd(a);
}
