#pragma once
#include <iostream>

typedef void (*funcPtr)(); // no args for this func.
funcPtr pFunc[3] = { NULL }; // array of pointers to functions

static void _array2() {
	// definition:
	pFunc[0] = &c;  // c() declared in array1.h
	pFunc[1] = &d;  // idem
	pFunc[0]();		// Dereferencin'an array o'func ptr syntax 1
	(*pFunc[1])();	// Dereferencin'an array o'func ptr syntax 2

	// !ERROR- Calling a NULL pointer:
	//pFunc[2]();
}