#pragma once
#include <iostream>
#include <string>

static void _fillInt(int a[], const int &_sz) {
	for(int i=0; i<_sz; i++)
		a[i] = 2;
}

static void _fillChar(char* a, const int &_sz) {
	for(int i=0; i<_sz; i++)
		a[i] = 'b';
}

static void _print(int a[], std::string name, const int &_sz) {
	for(int i=0; i<_sz; i++)
		std::cout << name << "[" << i << "] = " << a[i] << std::endl;
}

static void _print(char a[], std::string name, const int &_sz) {
	for(int i=0; i<_sz; i++)
		std::cout << name << "[" << i << "] = " << a[i] << std::endl;
}

static void _arguments() {
	int sz = 5;
	int  a1[5];
	char a2[5];
	memset(a1, 0, sz*sizeof(a1[0]));
	memset(a2, 0, sz*sizeof(a2[0]));
	_print(a1, "a1", sz);
	_print(a2, "a2", sz);

	// Initialize the arrays:
	_fillInt(a1, sz);
	_fillChar(a2, sz);
	_print(a1, "a1", sz);
	_print(a2, "a2", sz);

	// Heap memory:
	int *a3 = new int[sz];
	memset(a3, 0, sz*sizeof(a3[0]));
	_fillInt(a3, sz);
	_print(a3, "a3", sz);
}
