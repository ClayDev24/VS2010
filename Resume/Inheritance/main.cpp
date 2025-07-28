// Simple inheritance
//#include "vld.h" // No memory leaks DETECTED!
#include <iostream>
#include "public.h"
#include "private.h"
#include "protected.h"
using namespace std;

int main() {
	cout << "sizeof(Parent) = " << sizeof(Parent) << endl;
	cout << "sizeof(Child)  = " << sizeof(Child)  << endl;
	Child child;
	child.change();
	// Parent function interface comes through Child:
	child.read();
	child.permute();
	// Redefined functions hide base versions:
	child.set(12);

	// Private Inheritance:
	Goldfish bob;
	bob.eat();
	bob.sleep();
	bob.sleep(1);
	//bob.speak();// Error: private/protected member function

	// Protected Inheritance:
	Derived d;
	d.change(10);

	system("pause");
	return(0);
}

// INHERITANCE should NOT be used everywhere.
// This can result in awkward and overly-complicated designs.
// Instead, you should first look to COMPOSITION when creating new classes, since it is simpler and more flexible.
// If you take this approach, your designs will stay cleaner.