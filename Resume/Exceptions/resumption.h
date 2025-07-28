#pragma once
#include <iostream>
using namespace std;

int GetVal();

void _resumption() {
	bool good = false;
	// Resumption: Rectifies the exception condition and retries.
	do {
		try {
			GetVal(); // Keep tryin'vals till result is satisfactory
			cout << "The value you entered is okay.\n";
			good = true;
		}
		// Exceptions are like functions that always returns to the
		// Exception Handler: catch statements
		catch(const MyClass::MyError &ex) { // Ya need to write one exception handler per type. Works with polimorphism.
			cout << ex.what();
		} catch(const char *msg) { // Catches string types
			cout << msg;
		} catch(...) { // Catches everything didn't catched so far.
			cout << "Caught unknown exception!\n";
		} // If exception was caught normal execution flow resumes here on.
	} while(!good); // Manually transfer control to the beggining error prone code above
}

static int GetVal() {
	int n;
	cout << "Type a number from 4 to 8 (except 6): ";
	cin  >> n;
	// You can throw exception of any built-in types:
	if(n<4)
		throw MyClass::MyError("Value less than 4!\n"); // Throwing an obj o'my own class type.
	else if(n>8)
		throw "Value greater than 8!\n"; // throwing a string type.
	else if(n==6)
		throw n; // Throwing an int type

	return n;
}