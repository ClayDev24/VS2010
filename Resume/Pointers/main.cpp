//#include "vld.h" // No memory leaks DETECTED!
#include <iostream>
#include "arithmetic.h"
#include "pointer_to_member_function.h"
#include "void_pointer.h"
using namespace std;
// Pass by value:
void f1(float  f) { f = 1.1f; }
// Pass by reference usin' pointer (C/C++):
void f2(float *f) {*f = 2.2f; } // Dereferencin' a ptr.
// Pass by reference usin' reference (C++):
void f3(float &f) { f = 3.3f; }	// Clean syntax (Syntatic sugar).

int main() {
	_arithmetic();
	//_pointer_to_member_function();
	//_void_pointer();

	int* ipa, ipb, ipc; // Only ipa is a ptr! (C/C++)

	float f = 1.1f;
	cout << "f:" << f << endl;
	f1(f);  // val
	cout << "Pass by value   =>f :" << f << endl;
	f2(&f); // ptr
	cout << "Pass by ref(ptr)=>f :" << f << endl;
	f3(f);  // ref
	cout << "Pass by ref(&op)=>f :" << f << endl;

	_void_pointer();
		
	system("pause");
	return(0);
}