#pragma once
#include <iostream>

static void _character_array_literals() {
	std::cout << "__Character array literals:\n";
	char *cp   = "howdy"; // Compiler creates a Constant character array and returns its starting address.
	// Modifying any o'the chars in the array is a runtime error, although not all compilers (bcc32) enforce this correctly:
	//cp[2] = '_'; // *1- run-time error on this (vstudio 2008). Undefined behaviour, itll work on many machines.
	std::cout << cp << std::endl;
	// If you want to be able to modify the string, put it in an array:
	char cp2[] = "howdy"; // Safe to modify!
	cp2[2] = '#';
	std::cout << cp2 << std::endl;
}

// *1- Since compilers (like bcc32) don't enforce the diffeence you won't be reminded to use this latter form and so
// the point becomes rather subtle.