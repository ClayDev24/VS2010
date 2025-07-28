// Function to a pointer. Pág 198 TICPP v2
#pragma once
#include <iostream>
#include <vector>
//#include "..\..\include\define_print.h"

typedef void (*funcPtr1)(); // NO args...

static void noargsA() {
	std::cout << "No argments function A\n";
}

static void noargsB() {
	std::cout << "No argments function B\n";
}

static void _noArgs() {
	// Declaring a function pointer:
	funcPtr1 fp1;
	void (*fp2)();
	// Pointin' to a func syntax:
	fp1 = noargsA;
	fp2 = noargsA;
	// Dereferencin' ptr to call the func syntax 1
	(*fp1)();  // Syntax #1
	fp1();	  // Syntax #2
	(*fp2)(); // Syntax #1
	fp2();	  // Syntax #2
	// Pointin' to another function:
	fp1 = &noargsB;
	fp2 = &noargsB;
	// Dereferencin' ptr to call the func syntax 1
	(*fp1)();  // Syntax #1
	fp1();	  // Syntax #2
	(*fp2)(); // Syntax #1
	fp2();	  // Syntax #2
}