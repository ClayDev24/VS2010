// Handle implementation file
#include "Handle.h"

// Nested structure definition Safe hidden in a object file (obj/lib/dll) after compilation
struct Handle::Cheshire {
	int   i;	// Ya can change(add/sub) elements o'Cheshire at will,
	float f;	// n' the only file that must be recompiled is this 1, 'cuz .h file is untouched.				
};

void Handle::init() {
	smile    = new Cheshire; // Storage allocation
	smile->i = 0;
	smile->f = 12.34f;
}

void Handle::cleanup() {
	delete smile;	// Storage release
}

int Handle::get() {
	return smile->i;
}

void Handle::set(int x) {
	smile->i = x;
}