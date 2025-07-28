#pragma once
#include <iostream>

const int sz = 10;

struct X { int a[sz]; };

static void _print(X* x) {
	for(int i=0; i<sz; i++)
		std::cout << x->a[i] << ' ';
	std::cout << "\n--------------------\n";
}
// The least safe casting mechanism. The one most likely to produce bugs.
static void _reinterpret_cast() {
	X x;
	_print(&x);
	int* xp = reinterpret_cast<int*>(&x);
	for(int* i=xp; i<xp+sz; i++)
		*i=0;
	// Can't use xp as an X* at this point unless you cast it back:
	_print(reinterpret_cast<X*>(xp));
	// In this example, you can also just use the original identifier:
	_print(&x);
}