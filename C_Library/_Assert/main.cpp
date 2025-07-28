// Standard C Library
#include <stdio.h>
#include <assert.h>
// Standard C++ Library:
//#include <cstdio>
//#include <cassert>

int main() {
	FILE *datafile;
	datafile = fopen("clay.txt", "r");
	// A failed assertion indicates a invariant violation n' the program needs to be fixed.
	// If it evaluetes to true (non-zero) displays the line n' source file to the console.
	assert(datafile);
	fclose(datafile);
	
	return(0);
}