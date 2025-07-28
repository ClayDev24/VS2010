#pragma once
#include <iostream>

static void _const_cast() {
// Convertion from const to non-const (BREAKING THE CONSTINESS)
	const int i = 33;
	int* j = (int*)&i;			// Old-sytle deprecated form
	j  = const_cast<int*>(&i);	// new C++-style. Preferred

	// Some test:
	std::cout << "i:" << i << std::endl;
	//i++; // ERROR! Cannot change const var
	*j = 1;
	std::cout << "i:" << i << std::endl;

// Convertion from volatile to non-volatile:
	// Can't do simultaneous additional casting:
	//long* l = const_cast<long*>(&i); // Error
	volatile int k = 0;
	int* u = (int*)&k;			// Old-sytle deprecated form
	u  = const_cast<int*>(&k);	// new C++-style. Preferred
}