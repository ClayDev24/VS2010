#pragma once
#include <iostream>
using namespace std;

// Resource Acquisition Is Initialization (RAII):
// Resources control on obj lifetime.
template<class T, int sz = 1> class PWrap {
	T* ptr; // Class used to wrap pointer n' makin'em into objs
public:
	class RangeError {}; // Exception class
	PWrap() {
		ptr = new T[sz];
		cout << "PWrap()\n";
	}
	~PWrap() {
		delete []ptr;
		cout << "~PWrap()\n";
	}
	T& operator[](int i) throw(RangeError) {
		if(i >= 0 && i < sz) return ptr[i];
		throw RangeError();
	}
};

class UseResources2 {
	// This ptr objs are initialized BEFORE entering UseResources constructor.
	PWrap<Cat, 3> cats; // Never use naked (raw) pointers in your classes.
	PWrap<Dog>    dog;	// Instead use pointer wrapped in classes
public:
	UseResources2()  { cout << "UseResources()\n"; }
	~UseResources2() { cout << "~UseResources()\n"; }
};

static void _RAII() {
	try {
		// B4 UseResources was created an exception was thrown by the constructor of Dog
		// inside its template Wrapper PWrap
		UseResources2 ur;
	} catch(const int &i) { cout << "inside handler\n" << i << endl;
	} catch(...) { cout << "inside catch(...)\n"; }
}