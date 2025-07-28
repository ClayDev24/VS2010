#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
using std::exception;
using std::string;
using std::cout;
using std::endl;

// Std exception classes: logic_error | runtime_error | exception. See page 39 (TICPP vol2) for a description on the exception classes derived from the above: like domain_error, etc...
// Check out Std C++ lib exceptions b4 creatin' your own. If it ain't there try to inherit from one:
class MyClass {
	static int serie;
	int i;
public:
	MyClass():i(++serie) { cout << "MyClass():"  << i << endl; }
	~MyClass()           { cout << "~MyClass():" << i << endl; }
	// Tip: Nest you exceptions (page 56):
	class MyError : public exception {
	public:
		MyError(const string& msg = ""):exception(msg.c_str()) {}
		// Never be called 4 ptr exceptions. The exceptions handling system takes care o'all storage.
		~MyError() { cout << "~MyError()\n"; }
	};
	inline void myFuncA() throw(MyError) { throw MyError("MyError()"); }		// Throwing by value
	inline void myFuncB() throw(MyError) { throw /*new*/ MyError("MyError()"); }	// Throwing a ptr. It'll never be cleaned up.
};

int MyClass::serie = 0;

static void _MyError() {
	try {
		MyClass mc;
		//mc.myFuncA();
		mc.myFuncB(); 
		// Tip: Always Catch by reference 2 avoid obj slicin'or even duplicatin when passin'em into the handles:
	} catch(MyClass::MyError &me) {
		cout << me.what() << endl;	// what() is defined in exception class interface.
	} catch(MyClass::MyError *me) { // Catchin'pointer cause the ptr itself not to be destroyed.
		cout << me->what() << endl;
	}
	cout << "Execution resumes here.\n";
}