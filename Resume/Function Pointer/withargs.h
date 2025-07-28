// Function to a pointer. Pág 198 TICPP v2
#pragma once
#include <iostream>
#include <vector>

typedef void (*funcPtr2)(int, int); // WITH args...
typedef std::vector<funcPtr2> vFuncPtrArgs;

static void funcArgs(int _i, int _i2) {
	std::cout << "i=>  " << _i  << std::endl;
	std::cout << "i2=> " << _i2 << std::endl;
}

static void _withArgs() {
	// Declaring a function pointers:
	void (*fp1)(int, int);
	funcPtr2 fp2;
	// Pointin' to a functions:
	fp1 =  funcArgs;
	fp2 = &funcArgs;
	// Dereferencin' ptr to call the functions:
	(*fp1)(1, 2);  // Syntax #1
	(*fp2)(3, 4);
	fp1(5, 6);	  // Syntax #2
	fp2(7, 8);
}
