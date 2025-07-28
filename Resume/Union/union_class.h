#pragma once
#include <iostream>
// A union can also have a constructor, destructor
// member functions and even access control.
// Union cannot be used as a base class in inheritance.
union U {
private: // Access control tool
	// The int & float are stored at the same piece o'storage:
	int   i;
	float f;
public:
	U(int   a);
	U(float b);
	~U();
	int   get_int();
	float get_float();
};

U::U(int   a) { i = a; }
U::U(float b) { f = b; }
U::~U() { std::cout << "~U()\n"; }
int   U::get_int()   { return i; }
float U::get_float() { return f; }

void _union_class() {
	using namespace std;
	U x_int(12), xfloat(1.9F);
	cout << x_int.get_int()    << endl;
	cout << xfloat.get_float() << endl;
	// There's nothing to prevent such a mismatch:
	cout << x_int.get_float() << endl;
	cout << xfloat.get_int()  << endl;
	// There is still such a way to encapsulate union
	// inside a class to prevent the above. See SuperVar.h
}