#pragma once
#include <stdio.h>

// No return type:
//no_return() {		// C => returns int(default). C++ does NOT support default it.
//	return 77;		// C => Comments out this line to return garbage.
//};

static void no_return2() {};// C/C++.  Returns nothing.

static void _no_return_type() {
	
//	no_return(); // C
	no_return2();// C++
//	printf("no_return :%d\n", no_return());  // C
//	printf("no_return2:%d\n", no_return2()); // C/C++ => ERROR: func defines void as ret type.
}