//#include "vld.h" // No memory leaks DETECTED!
#include <iostream>
using namespace std;
// Global variables:
int dog, cat, bird, fish;

// Stored in code section:
void f(int pet) {
	cout << "pet id number: " << pet << endl;
}

int main() {
	// Local (automatic) variables:
	auto i=0;
	auto j=0;
	auto k=0; // Every local var defaults to auto (redundant here).
	cout << "f() : " << &f    << endl;
	cout << "dog : " << &dog  << endl;
	cout << "cat : " << &cat  << endl;
	cout << "bird: " << &bird << endl;
	cout << "fish: " << &fish << endl;
	cout << "i   : " << &i    << endl;
	cout << "j   : " << &j    << endl;
	cout << "k   : " << &k    << endl;

	system("pause");
	return(0);
}