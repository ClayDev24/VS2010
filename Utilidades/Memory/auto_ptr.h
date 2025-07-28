#pragma once
#include <iostream>
#include <memory>

static void _auto_ptr() {
	using namespace std;

	auto_ptr<int> p1(new int);
	*p1.get() = 10;

	auto_ptr<int> p2(p1); // Takes ownership from p1 and realeases it.

	cout << "p2 points to " << *p2 << "\n";
	// or:
	cout << "p2 points to " << *p2.get() << "\n"; // Returns a ptr to the obj pointed by the auto_ptr obj.
	// (p1 is now null-pointer auto_ptr)

	auto_ptr<int> p3;
	auto_ptr<int> p4;

	p3 = auto_ptr<int>(new int);

	*p3 = 11;
	p4 = p3;

	// ERROR:
	cout << "p4 points to " << *p4 << "\n";
	// (p is now null-pointer auto_ptr)
	cout << "p3 points to " << *p3 << "\n";	

	auto_ptr<int> auto_pointer(new int);
	int *manual_pointer;

	*auto_pointer = 33;

	manual_pointer = auto_pointer.release(); // Releases (sets to null) and returns its ptr.
	cout << "manual_pointer points to " << *manual_pointer << "\n";
	// (auto_pointer is now null-pointer auto_ptr)
	cout << "auto_pointer points to   " << *auto_pointer   << "\n";

	delete[] manual_pointer; 
}

