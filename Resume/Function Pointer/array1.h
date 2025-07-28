#pragma once
#include <iostream>

// A macro to define dummy functions:
#define DF(x) \
	void x##() { std::cout << "func " #x "()...\n"; }

DF(a); DF(b); DF(c); DF(d); DF(e); DF(f); DF(g);

// Array'o function pointers - Declaration + initialization 7 pointers:
void (*func_table[])() = { a, b, c, &d, &e, NULL, 0 }; // & symbol is optional!

static void _array1() {
	// Direct initialization:
	func_table[5] = &f;
	func_table[6] = &g;
	(*func_table[5])(); // Dereferencin'an array o'func ptr syntax 1
	(*func_table[6])(); // Dereferencin'an array o'func ptr syntax 1

	while(true) {
		std::cout << "<press>(a)~(g)||(q)uit\n";
		char c;
		std::cin >> c;
		if(c=='q') 
			break;
		if((c<'a')||(c>'g'))
			continue;
		(*func_table[c-'a'])();
	}
}