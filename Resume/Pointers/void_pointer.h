#pragma once
#include <iostream>
// You CANNOT have void references.
static void _void_pointer() {
	void*  vp;
	char   c = 'a';
	int    i = 99;
	float  f = 1.5;
	double d = 2.6;
	// The adrs o'ANY type can b assigned to a void ptr:
	vp = &c;
	vp = &f;
	vp = &d;
	vp = &i;
	// *vp = 3; // Compile-time ERROR. // Can't dereference a void pointer:
	*((int*)vp) = 123; // Castin'a void ptr.
	std::cout << "<<_Void Pointer_>>\n";
	std::cout << "*((int*)vp)=> " << *((int*)vp) << std::endl;
	std::cout << "i          => " << i << std::endl;
}