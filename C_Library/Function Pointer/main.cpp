#include <iostream>
void func1(int, char);		// Function prototype
void(*fptr)(int, char);  // Pointer to Function prototype

int main(void) {	
	fptr=func1; // Assignment

	// Callin' the Pointer to Function:
	(*fptr)(3, 'A');
	// Equivalent to:
	func1(3, 'A');

	system("pause");
	return(0);
}

void func1(int i, char c) {
	printf("i = %i\nc = %c\n", i, c);
}