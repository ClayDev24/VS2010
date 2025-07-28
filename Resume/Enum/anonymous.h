#pragma once
#include <iostream>

// Global anonymous union must be static (internal linkage):
static union {
	char c;
	long l;
};

static void _anonymous() {
	// Anonymous Union:
	union { // no type name...
		int   i;
		float f;
	}; // ...no variables name declared
	// Access members w/out usin' qualifiers:
	i = 12; // Access as ordinary variables
	std::cout << "i: " << i << std::endl;
	f = 1.22f; // W/out dot operator
	std::cout << "f: " << f << std::endl;
	// Union type access mismatch:
	std::cout << "i: " << i << "...type access mismatch(float as int)\n";
}