#pragma once
// Standard C Library. See page 86-87 TIPP (vol2)
#include <iostream>
#include <cstdio>
#include <cassert> // assert()

//#define NDEBUG
#ifdef NDEBUG
#define assert(cond) ((void)0)
#else
void assertImpl(const char* file, long line) {
	std::cout << file << ", line: " << line << std::endl;
};
#define ASSERT(cond) \
	((cond) ? (void)0 : assertImpl(__FILE__, __LINE__))
#endif

int _assertUsage() {
	FILE *file;
	errno_t err;
	if ((err = fopen_s(&file, "main.cpp", "r")) != 0)
		std::cout << "File was not opened: Error=>" << err << std::endl;
	else
		fclose(file);
	// A failed assertion indicates a invariant violation n' the program needs to be fixed.
	// Assertions is intended to be replaced later with robust exception error handling.
	// Also to verify design decisions that will only fail because programming logic.
	ASSERT(file); // Assertin'exp to be true. // If true = line & file =>console

	return(0);
}