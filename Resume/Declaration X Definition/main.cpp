// Declaration & Definition:
//#include "vld.h" // No memory leaks DETECTED!
#include <iostream>
#include "defines.h"
using namespace std;

extern int i;			// Declaration without definition (not allocate storage yet)
extern float f(float);	// Function declaration
float b;				// Declaration & definition (allocates storage already)

int i;					// Definition. Allocates storage

static int h(int x) {			// Declaration & definition
	return x + 1;
}

int main() {
	b = 1.0;
	i = 2;
	int x; // NOT initialized. Standard says its contents is undefined (garbage).
	x = 0;
	P_(x)
	P_(f(b))
	P_(h(i))

	system("pause");
	return(0);
}

float f(float a) {		// definition
	return static_cast<float>(a + 1.0);
}